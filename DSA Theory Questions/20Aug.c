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
printf("The linked list is : \n");
while(temp!=NULL){
    printf("%d\t",temp->data);
    temp=temp->next;
}
free(head);
free(middle);
free(last);
return 0;
}