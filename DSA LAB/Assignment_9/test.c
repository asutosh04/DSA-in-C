#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct node *root=NULL;

void treecreate(){
    struct node *p,*temp;
    int x;
    struct Queue q;
    create(&q,100);

    printf("Enter the root value : ");
    scanf("%d",&x);
    root=(struct node *)malloc(sizeof(struct node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("Enter the left child of %d : ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            temp=(struct node *)malloc(sizeof(struct node));
            temp->data=x;
            temp->lchild=temp->rchild=NULL;
            p->lchild=temp;
            enqueue(&q,temp);
        }
        printf("Enter the right child of %d : ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            temp=(struct node *)malloc(sizeof(struct node));
            temp->data=x;
            temp->lchild=temp->rchild=NULL;
            p->rchild=temp;
            enqueue(&q,temp);
        }
    }
}

struct node * search(struct node *T, int x) {
    if(T == NULL) return NULL;
    if(x == T -> data) {
        return T;
    }
    struct node* result =search(T -> lchild, x);
    if (result)
        return result;

    result =search(T -> rchild, x);
    if (result)
        return result;

    return NULL;
}

void preorder(struct node *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    else
    {
        printf("%d -> ", t->data);
        if (t->lchild!= NULL)    
            preorder(t->lchild);
        if (t->rchild!= NULL)    
            preorder(t->rchild);
    }
}

int main()
{
    treecreate();
    preorder(root);
    int num;
    printf("\nEnter the number you want to search : ");
    scanf("%d",&num);
    if(search(root,num)){
        printf("The element %d is present in the tree.",num);
    }
    else{
        printf("The element %d is not present in the tree.",num);
    }
    return 0;
}