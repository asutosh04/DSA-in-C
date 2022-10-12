#include <stdio.h>
#include <stdlib.h>

struct node{
    int roll_no;
    char name[20];
    float cgpa;
    char branch[10];
    struct node *next;
};
struct node *head=NULL;
struct node *temp=NULL;

int main(){
    struct node *list;
    int n;
    printf("Enter the number of students : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        list=malloc(sizeof(struct node));
        printf("\nEnter the data of student %d : ",i+1);
        printf("\nRoll no : ");
        scanf("%d",&list->roll_no);
        printf("Name : ");
        scanf("%s",list->name);
        printf("CGPA : ");
        scanf("%f",&list->cgpa);
        printf("Branch : ");
        scanf("%s",list->branch);
        list->next=NULL;
        if(head==NULL){
            head=list;
        }
        else{
            for(temp=head;temp->next!=NULL;temp=temp->next);
            temp->next=list;
        }
    }
    temp=head;
    while(temp!=NULL){
        printf("[%d , %s , %0.1f , %s]\n",temp->roll_no,temp->name,temp->cgpa,temp->branch);
        temp=temp->next;
    }
    struct node *new_node=NULL;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data of the new student : ");
    printf("\nRoll no : ");
    scanf("%d",&new_node->roll_no);
    printf("Name : ");
    scanf("%s",new_node->name);
    printf("CGPA : ");
    scanf("%f",&new_node->cgpa);
    printf("Branch : ");
    scanf("%s",new_node->branch);
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
    }
    else{
        temp=head;
        head=new_node;
        new_node->next=temp;
    }
    printf("After insertion : \n");
    temp=head;
    while(temp!=NULL){
        printf("[%d , %s , %0.1f , %s]\n",temp->roll_no,temp->name,temp->cgpa,temp->branch);
        temp=temp->next;
    }

    free(list);
    free(temp);
    free(new_node);

    return 0;  
}

