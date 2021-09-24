#include <stdio.h>
#include <stdlib.h>

struct PriorityQueue
{
    int data, priority;
};
int rear = -1, size = 5;

void enqueue(struct PriorityQueue arr[], int data, int priority)
{
    if (rear == size) // isFull
        printf("Queue is full.\n");
    else if (rear == -1) // isEmpty
    {
        rear = 0;
        arr[rear].data = data;
        arr[rear].priority = priority;
        rear++;
        printf("Enqueued %d with priority %d.\n", data, priority);
    }
    else
    {
        arr[rear].data = data;
        arr[rear].priority = priority;
        rear++;
        printf("Enqueued %d with priority %d.\n", data, priority);
    }
}

int findHighestPriority(struct PriorityQueue arr[])
{
    int lowest = 101;
    if (rear != -1) // isNotEmpty
    {
        for (int i = 0; i < rear; i++)
        {
            if (arr[i].priority < lowest)
                lowest = arr[i].priority;
        }
    }
    return lowest;
}

void dequeue(struct PriorityQueue arr[])
{
    if (rear == 0)
        printf("Queue is empty!\n");
    else
    {
        int index, priority = findHighestPriority(arr);

        // Finding the position where priority is
        for (int i = 0; i < rear; i++)
        {
            if (arr[i].priority == priority)
            {
                index = i;
                break;
            }
        }

        printf("Dequeued %d with highest priority %d.\n", arr[index].data, arr[index].priority);

        // Shifting the positions to left
        for (int j = index; j < rear; j++)
        {
            arr[j].data = arr[j + 1].data;
            arr[j].priority = arr[j + 1].priority;
        }
        rear--;
    }
}

void show(struct PriorityQueue arr[])
{
    for(int i = 0; i < rear; i++)
        printf("%d with priority %d.\n", arr[i].data, arr[i].priority);        
}

int main()
{
    struct PriorityQueue pq[size];
    
    // Taking user input
    start: //goto
    printf("Enter the operation:\n");
    printf("1: To enqueue.\n");
    printf("2: To dequeue.\n");
    printf("3: To show queue data.\n");
    printf("4. To exit.\n");

    int x;
    scanf("%d", &x);
    switch (x)
    {
        case 1:
        {
            printf("Enter the value: ");
            int d, p;
            scanf("%d", &d);
            printf("Enter the priority: ");
            scanf("%d", &p);
            enqueue(pq, d, p);
            printf("\n");
            goto start;
            break;
        }
        case 2:
        {
            dequeue(pq);
            printf("\n");
            goto start;
            break;
        }
        case 3:
        {
            show(pq);
            printf("\n");
            goto start;
            break;
        }
        case 4:
        {
            return 0;
            break;
        }
        default:
        {
            printf("\n");
            goto start;
        }
    }

    return 0;
}
