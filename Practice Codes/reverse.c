#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*prev,*curr,*temp,*list;
int main(){
    int n;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    struct node *head=NULL;
    for (int i = 0; i < n; i++)
    {
        list = malloc(sizeof(struct node));
        printf("\nEnter the data of node %d : ",i+1);
        scanf("%d", &list->data);
        list->next = NULL;
        if (head == NULL)
            head = list;
        else{
            for(temp=head;temp->next!=NULL;temp=temp->next);
            temp->next=list;
        }
    }

printf("\nThe linked list is : ");
temp=head;
do
{
    printf("%d ",temp->data);

    temp=temp->next;
}   while(temp!=NULL);

prev=NULL;
curr=NULL;
temp=head;
while (temp!=NULL){
    prev=curr;
    curr=temp;
    temp=temp->next;
    curr->next=prev;
}
head=curr;

printf("\nThe linked list after reversing is : ");
temp=head;
do
{
    printf("%d ",temp->data);

    temp=temp->next;
}   while(temp!=NULL);


return 0;
}

