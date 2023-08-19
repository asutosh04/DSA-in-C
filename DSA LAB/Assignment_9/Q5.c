/*Write a C program to implement Level Order Search or Breadth-First Search (BFS).*/

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Queue q;
    
void treecreate(){
    struct node *p,*temp;
    int x;
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

/*level order traversal*/
void leveorder(struct node *root){
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

int main()
{
    treecreate();
    printf("\n");
    leveorder(root);
    return 0;
}