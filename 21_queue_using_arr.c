#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int peek(struct queue *q, int ind)
{
    return q->arr[ind];
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
        return 1;
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
        return 1;
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
        printf("This queue is full\n");
    else
    {
        q->r++;
        q->arr[q->r] = val;
        printf("Entered number %d\n", val);
    }
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
        printf("This queue is empty\n");
    else
    {
        q->f++;
        return q->arr[q->f];
    }
    return INT_MIN;
}

void traversal(struct queue *q)
{
    for (int i = q->f+1; i < q->r + 1; i++)
    {
        if(i == -1){
            printf("The queue is empty\n");
        }
        printf("%d\n", q->arr[i]);
    }
}

int main()
{
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    int choice;

    while (1)
    {
        printf("\n\nEnter Your choice\n");
        printf("1) Insertion\n");
        printf("2) Deletion\n");
        printf("3) Peek\n");
        printf("4) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n\n");
        if (choice == 1)
        {
            int val, n;
            printf("How many value you want to insert: ");
            scanf("%d", &n);
            for(int i = 0; i < n; i++)
            {
                printf("Enter the value to be inserted: ");
                scanf("%d", &val);
                enqueue(&q, val);
            }
            printf("Queue after insertion\n");
            traversal(&q);
        }
        else if (choice == 2)
        {
            printf("Deleted %d from the queue\n", dequeue(&q));
            printf("Queue after deletion\n");
            traversal(&q);
        }
        else if (choice == 3)
        {
            int ind;
            printf("Enter the index you want to peek: ");
            scanf("%d", &ind);
            printf("The value at index %d is %d\n", ind, peek(&q, ind));
        }
        else if (choice == 4)
        {
            break;
        }
        else{
            printf("Invalid choice\n");
        }
    }

    return 0;
}