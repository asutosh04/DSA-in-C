#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
int main(){
struct node *head=(struct node *)malloc(sizeof(struct node));
struct node *middle=(struct node *)malloc(sizeof(struct node));
struct node *last=(struct node *)malloc(sizeof(struct node));

printf("Enter the data of first node : ");
scanf("%d",&head->data);

printf("\nEnter the data of second node : ");
scanf("%d",&middle->data);

printf("\nEnter the data of third node : ");
scanf("%d",&last->data);

head->next=middle;
middle->next=last;
last->next=NULL;
struct node *temp=head;
printf("The linked list is : ");
do
{
    printf("%d ",temp->data);

    temp=temp->next;
}   while(temp!=NULL);


return 0;
}