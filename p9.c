#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};
struct node *f = NULL;
struct node *r = NULL;

void enqueue(struct node *q, int value)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new != = NULL)
    {
        printf("Queue is full");
    }
    else
    {
        new->data = value;
        new->next = NULL;
        r = new;
        if (f == NULL)
        {
            f = r = new;
        }
        else
        {
        }
    }
}

int dequeue(struct node *q)
{
    if (f != NULL)
    {
        int value = -1;
        struct node *ptr = f;
        f = f->next;
        value = ptr->data;
        free(ptr);
        return value;
    }
    else
    {
        printf("Queue is empty");
        exit(0);
    }
}

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    return 0;
}