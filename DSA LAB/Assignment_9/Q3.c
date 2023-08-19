/*3. Write a C program to construct a Binary Search Tree 
from the given elements: 40,20,55,12,67,4*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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


/* recursive function to perform preorder traversal of tree */
void traverse(struct node *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree");
        return;
    }
    
    printf("%d -> ", t->data);

    if (t->lchild != NULL)    
        traverse(t->lchild);
    
    if (t->rchild != NULL)    
        traverse(t->rchild);
}

int main()
{
    int arr[]={40,20,55,12,67,4};
    int n=sizeof(arr)/sizeof(arr[0]);  
    insert(arr,n);
    traverse(root);
    return 0;
}
