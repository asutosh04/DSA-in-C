#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;
void enqueue(){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nQueue is full\n");
    }
    else
    {
        printf("\nEnter the data you want to queue : ");
        scanf("%d",&temp->data);
        temp->next=NULL;

        if(front==NULL)
        {
            front=rear=temp;
        }
        else
        {
            rear->next=temp;
            rear=temp;
        }
    }
}

int dequeue()
{
    int x=-1;
    struct node *temp;
    if(front==NULL)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        x=front->data;
        temp=front;
        front=front->next;
        free(temp);
    }
    return x;
}

void traverse(){
    if(front==NULL)
    {
        printf("\nQueue is empty.\nPlease Enqueue some values to display!\n");
    }
    else
    {
        struct node *p=front;
        while(p!=NULL)
        {
            printf("%d\t",p->data);
            p=p->next;
        }
    }
}

int main()
{
    int size,choice,item;
    while(1)
    {
        printf("\n\t\tLINK LIST QUEUE MENU\t\t\n");
        printf("\n1.Enqueue\n");
        printf("\n2.Dequeue\n");
        printf("\n3.Traverse\n");
        printf("\n4.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            item=dequeue();
            if(item==-1)
            {
                printf("No Elements Deleted.\n");
            }
            else
            {
                printf("\nDeleted element is  %d\n",item);
            }
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(1);
        default:
            printf("\nWrong choice\n");
        }/*End of switch*/
    }/*End of while*/

    return 0;
}