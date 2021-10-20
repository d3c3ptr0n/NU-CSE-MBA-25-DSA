#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void preOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

void postOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

int search(int inorder[], int start, int end, int current)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == current)
            return i;
    }
    return -1;
}

int INDEX = 0;
struct Node *buildTree(int preorder[], int inorder[], int start, int end)
{
    // base condition
    if (start > end)
        return NULL;

    int current = preorder[INDEX];
    INDEX++;

    struct Node *root = createNode(current);
    if (start == end)
        return root;

    int position = search(inorder, start, end, current);

    root->left = buildTree(preorder, inorder, start, position - 1);
    root->right = buildTree(preorder, inorder, position + 1, end);

    return root;
}

int main()
{
    int n;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &n);

    printf("\n");
    int preorder[n];
    printf("Enter the preorder sequence: \n");
    for(int i = 0; i < n; i++)
    {
        printf("Enter the value for index %d: ", i);
        scanf("%d", &preorder[i]);
    }

    printf("\n");
    int inorder[n];
    printf("Enter the inorder sequence: \n");
    for(int i = 0; i < n; i++)
    {
        printf("Enter the value for index %d: ", i);
        scanf("%d", &inorder[i]);
    }

    struct Node *root = buildTree(preorder, inorder, 0, n - 1);

    printf("\n");
    printf("Preorder Traversal: ");
    preOrderTraversal(root);

    printf("\n");
    printf("Inorder Traversal: ");
    inOrderTraversal(root);

    printf("\n");
    printf("Postorder Traversal: ");
    postOrderTraversal(root);

    return 0;
}