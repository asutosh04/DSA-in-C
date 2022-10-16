#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *temp = NULL;
struct node *list=NULL;

void create(){
    int n;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        list = malloc(sizeof(struct node));
        printf("\nEnter the data of node %d : ",i+1);
        scanf("%d", &list->data);
        list->next=NULL;
        if (head == NULL)
            head = list;
        else{
            for(temp=head;temp->next!=NULL;temp=temp->next);
            temp->next=list;
        }
    }
    list->next=head;

}

void traverse()
{
temp=head;
printf("\nThe linked list is : ");
if(head==NULL){
    printf("'EMPTY'\n");
}
else{
do
{
    printf("%d ",temp->data);
    temp=temp->next;
}while(temp!=head);
}
}

int main(){
    create();
    traverse();
    return 0;
}