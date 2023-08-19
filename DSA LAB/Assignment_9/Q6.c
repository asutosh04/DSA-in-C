/*Write a C program to implement Depth-First Search (DFS) on a given BST.*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*struct node {
    int data;
    struct node *l;
    struct node *r;
}*root = NULL, *temp = NULL;*/

/* Function to search the appropriate position to insert the new node */
void search(struct node *t)
{
    if ((temp->data > t->data) && (t->rchild != NULL))      /* data more than root node data insert at right */
        search(t->rchild);
    else if ((temp->data > t->data) && (t->rchild == NULL))
        t->rchild = temp;
    else if ((temp->data < t->data) && (t->lchild != NULL))    /* data less than root node data insert at left */
        search(t->lchild);
    else if ((temp->data < t->data) && (t->lchild == NULL))
        t->lchild = temp;
}

/* To insert a node in the tree */
void insert(int arr[],int n)
{
    
    for(int i=0;i<n;i++){
        temp = (struct node *)malloc(1*sizeof(struct node));
        temp->data = arr[i];
        temp->lchild = temp->rchild = NULL;
        if(i==0){
            root=temp;
        }
        search(root);    
    }
}

void depthfirstsearch(struct node *root){
    struct stack stk;
    struct node *p;
    stackcreate(&stk,100);
    push(&stk,root);
    while(!isemptystack(stk)){
        p=pop(&stk);
        if(p->rchild){
            push(&stk,p->rchild);
        }
        if(p->lchild){
            push(&stk,p->lchild);
        }
        printf("%d -> ",p->data);
    }
}

int main()
{
    int arr[]={40,30,50,25,35,45,60};
    int n=sizeof(arr)/sizeof(arr[0]); 
    insert(arr,n);
    depthfirstsearch(root);
    return 0;
}