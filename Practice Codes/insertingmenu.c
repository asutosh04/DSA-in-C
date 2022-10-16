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
printf("\n");
int ch,n=1;
printf("\n\n--------INSERT DATA--------\n");
printf("\nENTER 1 FOR INSERTING AT FIRST\nENTER 2 FOR INSERTING AT ANY POSITION\nENTER 3 FOR INSERTING AT LAST\nENTER 4 TO EXIT\n");
printf("ENTER YOUR CHOICE : ");
scanf("%d",&ch);
struct node *newnode=(struct node *)malloc(sizeof(struct node));
int pos;
while(n==1)

{
switch (ch)

{

case 1 :

printf("Enter the data of the node which you want to insert at first: ");
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
exit(0);
break;


case 2 : 

printf("Enter the position of the node where you want to instrt : ");
scanf("%d",&pos);

if(pos>0){

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
    temp1=temp->next;
    temp->next=newnode;
    newnode->next=temp1;
    }
}

printf("\nThe linked list after inserting is : \n\n");
temp=head;
while(temp!=NULL){
printf("%d\t",temp->data);
temp=temp->next;
}
free(temp);
free(temp1);
free(newnode);
}

else
printf("\nThe position you have entered is not valid!!!Error!!!");
free(head);
free(middle);
free(last);
free(temp);

exit(0);
break;


case 3 : 

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

exit(0);
break;


case 4 :
exit(0);
break;

}

}

return 0;
}