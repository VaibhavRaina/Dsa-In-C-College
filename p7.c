#include <stdio.h>
#include <stdlib.h>

struct CQueue
{
    int f;
    int r;
    int size;
    int *arr;
};

int isFull(struct CQueue *q)
{
    if ((q->r) % (q->size) == q->f)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct CQueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct CQueue *q, int value)
{
    if (isFull(q))
    {
        printf("queue is already full\n");
    }
    else
    {
        q->r = (q->r + 1) % (q->size);
        q->arr[q->r] = value;
    }
}

int dequeue(struct CQueue *q)
{
    int val = -1;
    if (isEmpty(q))
    {
        printf("queue is empty\n");
    }
    else
    {
        q->f = (q->f + 1) % (q->size);
        val = q->arr[q->f];
    }
    return val;
}
int main()
{
    while (1)
    {
        struct CQueue *q = (struct CQueue *)malloc(sizeof(struct CQueue));
        int choice;
        int value;
        q->r = -1;
        q->f = -1;
        printf("Enter the size of queue\n");
        scanf("%d", q->size);
        q->arr = (int *)malloc((q->size) * sizeof(int));
        printf("1:1 for Enqueue\n 2:2 for dequeue\n 3:3 for exit");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element you want to enqueue");
            scanf("%d", &value);
            enqueue(q, value);
            break;
        case 2:
            printf("dequeue");
            dequeue(q);
            break;
        case 3:
            exit(1);
            break;
        }
    }
}