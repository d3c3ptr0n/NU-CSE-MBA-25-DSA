#include<stdio.h>
#include<stdlib.h>

struct Queue 
{
    int size, i, j;
    int* array;
};

void enqueue(struct Queue* ptr, int val)
{
    if(ptr->j == ptr->size - 1)
        printf("Queue Overflow!!\n");
    else
    {
        ptr->j++;
        ptr->array[ptr->j] = val;
        printf("Enqueued: %d\n", val);
    }

}

int dequeue(struct Queue* ptr)
{
    int val = -1;
    if(ptr->i == ptr->j + 1)
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

    enqueue(&q, 10);
    printf("Dequeued: %d\n\n", dequeue(&q));

    enqueue(&q, 20);
    printf("Dequeued: %d\n\n", dequeue(&q));

    enqueue(&q, 30);
    printf("Dequeued: %d\n\n", dequeue(&q));

    enqueue(&q, 40);
    printf("Dequeued: %d\n\n", dequeue(&q));

    enqueue(&q, 50);
    printf("Dequeued: %d\n\n", dequeue(&q));

    enqueue(&q, 60);


    return 0;
}
