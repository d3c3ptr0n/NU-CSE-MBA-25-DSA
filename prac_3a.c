#include<stdio.h>
#include<stdlib.h>
struct CircularQueue
{
    int size, i, j, n;
    int* array;
};

// Function to check if queue is full or not
int isFull(struct CircularQueue* ptr)
{
    if(((ptr->j+1) % ptr->size) == ptr->i)
        return 1;
    return 0;
}

// Function to check if queue is empty or not
int isEmpty(struct CircularQueue* ptr)
{
    if(ptr->j == -1 && ptr->i==-1)
        return 1;
    return 0;
}

// Enqueue operation
void enqueue(struct CircularQueue* ptr, int val)
{   
    if(isFull(ptr))
        printf("Queue is Full!!\n");
    else if(isEmpty(ptr))
    {
        ptr->i = 0;
        ptr->j = 0;
        ptr->array[ptr->j] = val;
        printf("Enqueued: %d\n", val);
        ptr->n++;
    }
    else
    {
        ptr->j = (ptr->j+1)%ptr->size;
        ptr->array[ptr->j] = val;
        printf("Enqueued: %d\n", val);
        ptr->n++;
    }
}

// Dequeue operation
int dequeue(struct CircularQueue* ptr)
{
    for(int i = 0; i < ptr->size; i++)
        ptr->array[i] = 0;
    ptr->i = ptr->j = -1;
    printf("Removed all the activities.\n");
}

// To show queue data
void show(struct CircularQueue* ptr)
{   
    int a = 1;
    int front = ptr->i, rear = ptr->j;

    if(front == -1)
        printf("The queue is empty.\n");
    else if(front <= rear)
    {
        for(int i = front; i <= rear; i++)
        {
            printf("At %d: %d\n", a, ptr->array[i]);
            a++;
        }
    }
    else
    {
        for(int i = front; i < ptr->size; i++)
        {
            printf("At %d: %d\n", a, ptr->array[i]);
            a++;
        }
        front = 0;
        for(int i = front; i <= rear; i++)
        {
            printf("At %d: %d\n", a, ptr->array[i]);
            a++;
        }
    }
}

int main()
{
    // queue intialisation
    struct CircularQueue q;
    q.size = 5;
    q.i = q.j = -1;
    q.n = 0;
    q.array = (int*)malloc(sizeof(int)*q.size);
    for(int i = 0; i < q.size; i++)
        q.array[i] = 0;
    
    // Taking user input
    start: //goto 
    printf("Enter the operation:\n");
    printf("1: To add a printer activity.\n");
    printf("2: To remove activities.\n");
    printf("3: To show all running activities.\n");
    printf("4: To exit.\n");

    int x; scanf("%d", &x);
    switch(x)
    {
        case 1:
        {
            printf("Enter the ID: ");
            int n; scanf("%d", &n);
            enqueue(&q, n);
            printf("\n");
            goto start;
            break;
        }
        case 2:
        {
            dequeue(&q);
            printf("\n");
            goto start;
            break;
        }
        case 3:
        {
            show(&q);
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
