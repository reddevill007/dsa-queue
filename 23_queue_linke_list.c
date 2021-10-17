#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* f = NULL;
struct Node* r = NULL;

void traversal(struct Node *ptr)
{
    printf("Printing the elemnts of the linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));

    if(n == NULL)
        printf("Queue is full");
    else
    {
        n->data = val;
        n->next = NULL;
        if(f == NULL)
            f = r = n;
        else
        {
            r->next = n;
            r = n;
        }
        
    }
    
}

int dequeue()
{
    int val = INT_MIN;
    struct Node* ptr = f;
    if(f == NULL)
        printf("queue is empty\n");
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    printf("Dequeuing element %d\n", dequeue());
    enqueue(34);
    enqueue(3);
    enqueue(3);
    enqueue(24);
    traversal(f);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    traversal(f);

    return 0;
}