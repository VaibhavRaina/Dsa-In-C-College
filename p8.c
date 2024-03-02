#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

struct Node *push(struct Node *head, int data)
{
    if (top != NULL)
    {
        printf("Stack is not empty, cannot push more\n");
    }
    else
    {
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = head;
        top = ptr;
        return ptr;
    }
}
struct Node *pop(struct Node *head)
{
    if (top != NULL)
    {
        struct Node *temp = top;
        top = top->next;
        free(temp);
    }
    else
    {
        printf("Stack is empty !!\n");
    }
    return head;
}

void display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void isEmpty()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }
}

int peek(struct Node *head, int index)
{
    struct Node *ptr = head;
    if (ptr != NULL)
    {
        for (int i = 0; i < index - 1; i++)
        {
            ptr = ptr->next;
        }
        return ptr->data;
    }
    else
    {
        return -1;
    }
}
int main()
{
    struct Node *head = NULL;

    // Example usage
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);

    display(head);

    pop(head);
    display(head);
    printf("%d", peek(head, 2));
    isEmpty();
    isFull();

    return 0;
}
