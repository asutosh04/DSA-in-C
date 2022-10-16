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
head->next=middle;
printf("\nEnter the data of second node : ");
scanf("%d",&middle->data);
middle->next=last;
printf("\nEnter the data of third node : ");
scanf("%d",&last->data);
last->next=NULL;
struct node *temp=head;
printf("\nThe linked list that you have entered is : \n\n");
while(temp!=NULL){
    printf("%d\t",temp->data);
    temp=temp->next;
}
struct node *newnode=(struct node *)malloc(sizeof(struct node));
printf("\n\nEnter the data of the node which you want to insert at first: ");
scanf("%d",&newnode->data);
if(head==NULL)
head=newnode;
else{
    newnode->next=head;
    head=newnode;
}
temp=head;
printf("\nThe linked list after inserting is : \n\n");
while(temp!=NULL){
    printf("%d\t",temp->data);
    temp=temp->next;
}
free(head);
free(middle);
free(last);
free(temp);
free(newnode);
return 0;
}