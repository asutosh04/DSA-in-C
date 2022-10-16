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
    struct node *list,*temp,*prev;
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

    int pos,i=1;
    printf("\nEnter the position that you want to delete : ");
    scanf("%d",&pos);

    if(pos==1){
        temp=head->next;
        free(head);
        head=temp;
    }
    else{
    for(temp=head;i<pos;temp=temp->next,++i){
    prev=temp;
    }
    prev->next=temp->next;
    free(temp);
    }

    temp=head;
    printf("\nThe list after deleting is : ");
    do 
    {
        printf("%d ",temp->data);
        temp=temp->next;
    } while (temp!=NULL);

    return 0;
}