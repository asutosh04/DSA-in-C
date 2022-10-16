#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*head=NULL;
int main(){
int n;
printf("Enter the number of nodes you want to create : ");
scanf("%d",&n);
if(n!=0){
struct node *newnode=(struct node *)malloc(sizeof(struct node));
head=newnode;
printf("Enter the data of the 1 node : ");
scanf("%d",&head->data);

struct node *temp=head;
for (int i=2;i<=n;i++){
    newnode=(struct node *)malloc(sizeof(struct node));
    temp->next=newnode;
    printf("Enter the data of the %d node : ",i);
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    temp=temp->next;
}
printf("The linked list is : ");
temp=head;
while(temp!=NULL)
{
    printf("%d ",temp->data);

    temp=temp->next;
}
}
return 0;
}