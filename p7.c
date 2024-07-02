#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Cq
{
    int f;
    int r;
    int size;
    int *arr;
};

int isFull(struct Cq *q)
{
    if ((q->r + 1) % (q->size) == q->f)
    {
        printf("Queue is full\n");
        return 1;
    }
    return 0;
}

int isEmpty(struct Cq *q)
{
    if (q->r == q->f)
    {
        printf("Queue is empty\n");
        return 1;
    }
    return 0;
}

void enqueue(struct Cq *q, int data)
{
    if (isFull(q))
    {
        return;
    }
    q->r = (q->r + 1) % q->size;
    q->arr[q->r] = data;
}

int dequeue(struct Cq *q)
{
    int value = -1;
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return value;
    }
    q->f = (q->f + 1) % q->size;
    value = q->arr[q->f];
    return value;
}

void display(struct Cq *q)
{
    int i = (q->f + 1) % q->size;
    while (i != (q->r + 1) % q->size)
    {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main()
{
    struct Cq *q = malloc(sizeof(struct Cq));
    q->f = q->r = 0;
    int n = -1, data;
    printf("Enter size of queue: ");
    scanf("%d", &(q->size));
    q->arr = malloc(q->size * sizeof(int));
    printf("Enter 1: for adding\n");
    printf("Enter 2: for removing\n");
    printf("Enter 3: for displaying\n");
    printf("Enter 4: for exiting\n");
    while (n != 4)
    {
        printf("Enter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &data);
            enqueue(q, data);
            break;
        case 2:
            printf("Dequeued element: %d\n", dequeue(q));
            break;
        case 3:
            printf("Displaying queue: ");
            display(q);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    free(q->arr);
    free(q);
    return 0;
}
