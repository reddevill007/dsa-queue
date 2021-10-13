#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct CircularQueue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct CircularQueue *q)
{
    if((q->r+1)%q->size == q->f)
        return 1;
    return 0;
}

int isEmpty(struct CircularQueue *q)
{
    if(q->r == q->f)
        return 1;
    return 0;
}

void enqueue(struct CircularQueue *q, int val)
{
    if(isFull(q))
        printf("This CircularQueue is full\n");
    else
    {
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct CircularQueue *q)
{
    if(isEmpty(q))
        printf("This CircularQueue is empty\n");
    else
    {
        q->f = (q->f+1)%q->size;
        return q->arr[q->f];
    }
    return INT_MIN;
}

int main()
{
    struct CircularQueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size*sizeof(int));

    printf("Queue is Empty: %d\n", isEmpty(&q));

    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q)); 
    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 45);
 
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
    return 0;
}