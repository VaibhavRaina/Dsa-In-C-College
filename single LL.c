#include<stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create(struct Node* head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

struct Node* insertAtFront(struct Node* head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

struct Node* insertInBetween(struct Node* head, int data, int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;

    while (i < index - 1 && p != NULL) {
        p = p->next;
        i++;
    }

    if (p == NULL) {
        printf("Index out of bounds\n");
        return head;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct Node*deleteFront(struct Node*head){
    struct Node*p=head;
    head=head->next;
    free(p);
    return head;
}

struct Node*deleteIndex(struct Node*head,int index){
    struct Node*p=head;
    struct Node*q=head->next;
    int i=0;
    while(i!=index-1){
        q=q->next;
        p=p->next;
    }
    p->next=q->next;
    free(q);
}


int main(){
    struct Node *head;
    return 0;
}
