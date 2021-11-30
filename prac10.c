#include<stdio.h>
#include<stdlib.h>

struct Edge
{
    int source, destination, weight;
};

// Sorting on basis of weight
void sortWeight(struct Edge graph[], int numberOfEdges) 
{
    for(int i = 0; i < numberOfEdges - 1; i++)
    {
        for(int j = i+1; j > 0; j--)
        {
            if(graph[j].weight < graph[j-1].weight) //swap
            {
                struct Edge temp = graph[j];
                graph[j] = graph[j-1];
                graph[j-1] = temp;
            }
            else
                break;
        }
    }
}

// Find the parent of given child
int findParent(int child, int parent[])
{
    if(child == parent[child])
        return child;
    parent[child] = findParent(parent[child], parent);
    return parent[child];
}

// Function create same parents
void unionParent(int sourceParent, int destinationParent, int parent[], int rank[])
{
    if(sourceParent == destinationParent)
        return;
    else if(rank[sourceParent] < rank[destinationParent])
        parent[sourceParent] = destinationParent;
    else if(rank[destinationParent] < rank[sourceParent])
        parent[destinationParent] = sourceParent;
    else
    {
        parent[destinationParent] = sourceParent;
        rank[sourceParent]++;
    }
}

// To print tree
void printTree(struct Edge tree[], int treeSize)
{
    for(int i = 0; i < treeSize; i++)
    {
        if(tree[i].source < tree[i].destination)
            printf("%d %d %d\n", tree[i].source, tree[i].destination, tree[i].weight);
        else
            printf("%d %d %d\n", tree[i].destination, tree[i].source, tree[i].weight);
    }
}

// Kruskal Algorithm to obtain MST
void kruskalAlgorithm(struct Edge graph[], int numberOfNodes, int numberOfEdges)
{
    // Sorting the graph array in ascending order on basis of the weight in each node
    sortWeight(graph, numberOfEdges);

    // Parent and rank array
    int parent[numberOfNodes], rank[numberOfNodes];
    for(int i = 0; i < numberOfNodes; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    // Building the tree
    struct Edge tree[numberOfNodes - 1];
    int minimumWeight = 0, treeSize = 0;
    for(int i = 0; treeSize < numberOfNodes - 1; i++)
    {
        struct Edge currentEdge = graph[i];
        int sourceParent = findParent(currentEdge.source, parent);
        int destinationParent  = findParent(currentEdge.destination, parent);

        if(sourceParent!=destinationParent)
        {
            tree[treeSize] = currentEdge;
            minimumWeight += currentEdge.weight;
            unionParent(sourceParent, destinationParent, parent, rank);
            treeSize++;
        }
    }

    // Printing the minimum weight
    printf("The minimum weight is: %d\n\n", minimumWeight);
    
    // Priting the MST
    printf("The tree formed is: \n");
    printTree(tree, treeSize); 
}

int main()
{
    // Number of nodes and edges in graph
    int numberOfNodes, numberOfEdges;
    printf("Enter the number of nodes: ");
    scanf("%d", &numberOfNodes);
    printf("Enter the number of edges: ");
    scanf("%d", &numberOfEdges);
    printf("\n");

    // graph data
    struct Edge graph[numberOfEdges];
    
    printf("Enter the graph data:\n");
    for(int i = 0; i < numberOfEdges; i++)
    {
        // Source
        printf("Enter the source of edge %d: ", i+1);
        scanf("%d", &graph[i].source);

        // Destination
        printf("Enter the destination of edge %d: ", i+1);
        scanf("%d", &graph[i].destination);

        // Weight
        printf("Enter the weight of edge %d: ", i+1);
        scanf("%d", &graph[i].weight);

        printf("\n");        
    }

    kruskalAlgorithm(graph, numberOfNodes, numberOfEdges);
    
    return 0;
}