#include<stdio.h>
#include<stdlib.h>
struct CircularQueue
{
    int size, i, j;
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
    }
    else
    {
        ptr->j = (ptr->j+1)%ptr->size;
        ptr->array[ptr->j] = val;
        printf("Enqueued: %d\n", val);
    }
}

// Dequeue operation
int dequeue(struct CircularQueue* ptr)
{
    if(isEmpty(ptr))
    {
        printf("Queue is Empty!!\n");
        return 0;
    }
    else if(ptr->i == ptr->j)
    {
        int x = ptr->array[ptr->i];
        printf("Dequeued: %d\n", x);
        ptr->array[ptr->i] = 0;
        ptr->i = -1;
        ptr->j = -1;
        return x;
    }
    else
    {
        int x = ptr->array[ptr->i];
        printf("Dequeued: %d\n", x);
        ptr->array[ptr->i] = 0;

        ptr->i = (ptr->i+1)%ptr->size;
        return x;
    }
}

// To show queue data
void show(struct CircularQueue* ptr)
{   
    int a = 1;
    for(int i = 0; i < ptr->size; i++)
    {
        if(ptr->array[i]!=0)
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
    q.array = (int*)malloc(sizeof(int)*q.size);
    for(int i = 0; i < q.size; i++)
        q.array[i] = 0;
    
    // Taking user input
    start: //goto 
    printf("Enter the operation:\n");
    printf("1: To add a printer.\n");
    printf("2: To remove a printer.\n");
    printf("3: To show all printers.\n");
    printf("4. To exit.\n");

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
