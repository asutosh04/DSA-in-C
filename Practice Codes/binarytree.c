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

/* recursive function to perform inorder traversal of tree */
void inorder(struct node *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    if (t->lchild!= NULL)    
        inorder(t->lchild);
    printf("%d -> ", t->data);
    if (t->rchild!= NULL)    
        inorder(t->rchild);
}

/* recursive function to perform preorder traversal of tree */
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

/* recursive function to perform postorder traversal of tree */
void postorder(struct node *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    if (t->lchild!= NULL)    
        postorder(t->lchild);
    if (t->rchild!= NULL)    
        postorder(t->rchild);
    printf("%d -> ", t->data);
}

/*level order traversal*/
void leveorder(struct node *root){
    struct Queue q;
    create(&q,100);
    printf("%d -> ",root->data);
    enqueue(&q,root);
    while(!isEmpty(q)){
        root=dequeue(&q);
        if(root->lchild){
            printf("%d -> ",root->lchild->data);
            enqueue(&q,root->lchild);
        }
        if(root->rchild){
            printf("%d -> ",root->rchild->data);
            enqueue(&q,root->rchild);
        }       
    }

}

/*Searching an element in a tree*/
struct node * search(struct node *T, int x) {
    if(T == NULL) return NULL;
    if(x == T -> data) {
        return T;
    }
    struct node *result;
    result = search(T -> lchild, x);
    if (result)
        return result;

    result = search(T -> rchild, x);
    if (result)
        return result;

    return NULL;
}

int main()
{
    treecreate();
    leveorder(root);
    return 0;
}
