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

printf("\nThe linked list you have entered is : \n");
struct node *check=head;
while(check!=NULL){
printf("%d\t",check->data);
check=check->next;
}

int pos;
printf("\nEnter the position of the node where you want to instrt : ");
scanf("%d",&pos);

if(pos>0){
struct node *newnode=(struct node *)malloc(sizeof(struct node));
printf("\nEnter the data of the node which you want to insert : ");
scanf("%d",&newnode->data);
struct node *temp=NULL;
struct node *temp1=NULL;
if(head==NULL){
head=newnode;
}
else{
    if(pos==1){
        newnode->next=head;
        head=newnode;
    }
    else{
    int i=1;
    for(temp=head;i<pos-1;temp=temp->next,++i);
    newnode->next=temp->next;
    temp->next=newnode;

    }
}

printf("\nThe linked list after inserting is : \n\n");
check=head;
while(check!=NULL){
printf("%d\t",check->data);
check=check->next;
}
free(temp);
free(temp1);
free(newnode);
free(check);
}

else
printf("\nThe position you have entered is not valid!!!Error!!!");
free(head);
free(middle);
free(last);
free(check);

return 0;
}