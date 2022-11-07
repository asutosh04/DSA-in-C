#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
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

/*iterative preorder traversal*/
void iterativepreorder(struct node *t){
    struct stack stk;
    stackcreate(&stk,100);

    while(t || !isemptystack(stk)){
        if(t){
            printf("%d ",t->data);
            push(&stk,t);
            t=t->lchild;
        }
        else{
            t=pop(&stk);
            t=t->rchild;
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

/*iterative inorder traversal*/
void iterativeinorder(struct node *t){
    struct stack stk;
    stackcreate(&stk,100);

    while(t || !isemptystack(stk)){
        if(t){
            push(&stk,t);
            t=t->lchild;
        }
        else{
            t=pop(&stk);
            printf("%d ",t->data);
            t=t->rchild;
        }
    }
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

/*iterative postorder traversal*/
void iterativepostorder(struct node *t){
    struct stack stk;
    long int tmp;
    stackcreate(&stk,100);

    while(t || !isemptystack(stk)){
        if(t){
            push(&stk,t);
            t=t->lchild;
        }
        else{
            tmp=pop(&stk);
            if(tmp>0){
                push(&stk,-tmp);
                t=((struct node*)tmp)->rchild;
            }
            else{
                printf("%d -> ",((struct node*)-tmp)->data);
            }
        }
        
    }
}

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
    postorder(root);
    printf("\n");
    iterativepostorder(root);

    return 0;
}

