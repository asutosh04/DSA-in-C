#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head=NULL;
int main()
{
    int n;
    struct node *list,*temp,*seclast;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        list=malloc(sizeof(struct node));
        printf("Enter the data of node %d : ",i+1);
        scanf("%d",&list->data);
        list->next=NULL;
        if(head==NULL)
            head=list;
        else {
            for(temp=head;temp->next!=NULL;temp=temp->next);
            temp->next=list;
        }
    }
    temp=head;
    printf("The list you have entered is : ");
    do 
    {
        printf("%d ",temp->data);
        temp=temp->next;
    } while (temp!=NULL);

    if(head->next==NULL){
        free(head);
    }
    else{
    for(temp=head;temp->next!=NULL;temp=temp->next){
    seclast=temp;
    }
    free(temp);
    seclast->next=NULL;
    }

    temp=head;
    printf("\nThe list after deleting is : ");
    if(head==NULL){
        printf("\nNo list exists");
    }
    else{
    do 
    {
        printf("%d ",temp->data);
        temp=temp->next;
    } while (temp!=NULL);
    }

    return 0;
}