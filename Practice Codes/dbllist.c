#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;
};

struct node *head,*tail= NULL;
struct node *temp = NULL;
struct node *list=NULL;

void create(){
    int n;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        list = malloc(sizeof(struct node));
        list->prev = NULL;
        printf("\nEnter the data of node %d : ",i+1);
        scanf("%d", &list->data);
        list->next = NULL;
        if (head == NULL || tail == NULL)
            head = list;
        else{
            for(temp=head;temp->next!=NULL;temp=temp->next);
            list->prev=temp;
            temp->next=list;
        }
        tail=list;
    }
}

void traverse()
{
int pick;
while(1){
    printf("\nEnter your choice\n");
    printf("\n1.From First.\n");
    printf("\n2.From Last.\n");
    printf("\n3.EXIT.\n");
    printf("\nCHOICE : ");
    scanf("%d",&pick);
    switch (pick)
    {
    case 1:
        temp=head;
        printf("\nThe linked list from start is : ");
        if(head==NULL){
        printf("'EMPTY'\n");
        }
        else{
        do
        {
            printf("%d ",temp->data);
            temp=temp->next;
        } while(temp!=NULL);
        }
        break;

    case 2:
        temp=tail;
        printf("\nThe linked list from end is : ");
        if(tail==NULL){
            printf("'EMPTY'\n");
        }
        else{
        do
        {
            printf("%d ",temp->data);
            temp=temp->prev;
        } while(temp!=NULL);
        }
        break;

    case 3:
        exit(1);
        break;
    default:
        printf("\nInvalid Entry!");
    }
}
}


int main(){
    create();
    traverse();
    return 0;
}