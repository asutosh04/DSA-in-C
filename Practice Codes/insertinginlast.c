#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
head->next=middle;
printf("\nEnter the data of second node : ");
scanf("%d",&middle->data);
middle->next=last;
printf("\nEnter the data of third node : ");
scanf("%d",&last->data);
last->next=NULL;

struct node *newnode=(struct node *)malloc(sizeof(struct node));
printf("\nEnter the data of the node which you want to insert at last: ");
scanf("%d",&newnode->data);
struct node *temp=NULL;
if(head==NULL)
head=newnode;
else{
    for(temp=head;temp->next!=NULL;temp=temp->next);
    temp->next=newnode;
    newnode->next=NULL;
}
printf("\nThe linked list is : \n\n");
temp=head;
while(temp!=NULL){
    printf("%d\t",temp->data);
    temp=temp->next;
}
free(head);
free(middle);
free(last);
free(newnode);
free(temp);
return 0;
}