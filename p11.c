#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void insertFront(struct node *head, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data=data;
    new->next = head;
    head->prev = new;
    new->prev = NULL;
    if (head != NULL)
    {
        new = head;
    }
}

void insertRear(struct node*head,int data){
    struct node *new = (struct node *)malloc(sizeof(struct node));
     struct node *ptr=head;
     while(ptr!=NULL){
        ptr=ptr->next;
     }
     new->data=data;
     ptr->next=new;
     new->prev=ptr;
     new->next=NULL;
}

void deleteFront(struct node*head){

    struct node*p=head;
    head=head->next;
    head->prev=NULL;
    p->prev=NULL;
    free(p);
}

void deleteRead(struct node*head){
    struct node*p=head;
    struct node*q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    q->prev=NULL;
    free(q);
}

int main()
{
    return 0;
}