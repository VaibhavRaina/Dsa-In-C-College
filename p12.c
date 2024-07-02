#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left;
    struct node *right;
    int data;
};

struct node *preOrder(struct node *p)
{
    if (p != NULL)
    {
        printf("%d", p->data);
        preOrder(p->left);
        preOrder(p->right);
    }
}

struct node *postOrder(struct node *p)
{
    if (p != NULL)
    {
        postOrder(p->left);
        postOrder(p->right);
        printf("%d", p->data);
        return p;
    }
}

struct node *inOrder(struct node *p)
{
    if (p != NULL)
    {
        inOrder(p->left);
        printf("%d", p->data);
        inOrder(p->right);
        return p;
    }
}

struct node *insert(struct node *root, int data)
{
    if (!root)
    {
        return create(data);
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->right)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        printf("Duplicate data");
    }
}

struct node *search(struct node *root, int target)
{
    if (!root)
    {
        return create(value);
    }
    else if (target < root->data)
    {
        root->left = search(root->left, data);
    }
    else if (target > root->data)
    {
        root->right = search(root->right, data);
    }
    else
    {
        printf("Not found\n");
    }
    return root;
}