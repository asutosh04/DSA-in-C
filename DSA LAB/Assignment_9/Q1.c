/*Write a C program to create a Binary Tree using linked list.*/

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

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

void preorder(struct node *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    printf("%d -> ", t->data);
    if (t->lchild!= NULL)    
        preorder(t->lchild);
    if (t->rchild!= NULL)    
        preorder(t->rchild);
}

int main()
{
    treecreate();
    preorder(root);
    return 0;
}