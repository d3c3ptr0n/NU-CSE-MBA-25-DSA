#include<stdio.h>
#include<stdlib.h>

struct Queue 
{
    int size, i, j;
    int* array;
};

void enqueue(struct Queue* ptr, int val)
{
    if((ptr->j - ptr->i) == ptr->size)
        printf("Queue Overflow!!\n");
    else
    {
        ptr->j++;
        ptr->array[ptr->j] = val;
    }
}

int dequeue(struct Queue* ptr)
{
    int val = -1;
    if((ptr->j - ptr->i) == 0)
        printf("Unable to remove element, Queue is empty!!\n");
    else
    {
        ptr->i++;
        val = ptr->array[ptr->i];
    }
    return val;
}

int main()
{
    struct Queue q;
    q.size = 5;
    q.i = -1;
    q.j = -1;
    q.array = (int*)malloc(sizeof(int)*q.size);

    enqueue(&q, 12);
    enqueue(&q, 15);

    printf("Dequeued %d\n", dequeue(&q));
    printf("Dequeued %d\n", dequeue(&q));
    printf("Dequeued %d\n", dequeue(&q));


    return 0;
}