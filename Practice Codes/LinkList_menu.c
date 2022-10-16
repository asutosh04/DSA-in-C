#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head,*temp,*list=NULL,*h1;
struct node *create(struct node *head){
    int n;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        list = malloc(sizeof(struct node));
        printf("\nEnter the data of node %d : ",i+1);
        scanf("%d", &list->data);
        list->next = NULL;
        if (head == NULL)
            head = list;
        else{
            for(temp=head;temp->next!=NULL;temp=temp->next);
            temp->next=list;
        }
    }
    return head;
}
struct node *insertfirst(struct node *head)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data which you want to insert : ");
    scanf("%d", &new_node->data);
    new_node->next=NULL;
    if (head == NULL)
        head = new_node;
    else
    {
        new_node->next = head;
        head = new_node;
    }
    return(head);
}

struct node *insertlast(struct node *head)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data which you want to insert : ");
    scanf("%d", &new_node->data);
    new_node->next=NULL;
    if (head == NULL)
        head = new_node;
    else
    {
        
        for (temp = head; temp->next != NULL; temp = temp->next)
            ;
        temp->next = new_node;
        new_node->next=NULL;
    }
    return(head);
}

struct node *insertanypos(struct node *head)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    int pos;
    printf("\nEnter the position where you want to insert : ");
    scanf("%d", &pos);
    printf("\nEnter the data which you want to insert : ");
    scanf("%d", &new_node->data);
    new_node->next=NULL;
    if (head == NULL)
        head = new_node;
    else
    {
        
        int i = 1;
        for (temp = head; i < pos - 1; temp = temp->next, ++i)
            ;
        struct node *temp1 = temp->next;
        temp->next = new_node;
        new_node->next = temp1;
    }
    return(head);
}

struct node *dltfirst(struct node *head)
{
    if(head==NULL){
        printf("\n\n'List is Empty'\nInsert some data and try again!");
    }
    else{
    temp=head;
    head=head->next;
    free(temp);
    }
    return(head);
}

struct node *dltlast(struct node *head)
{
    if(head==NULL){
    printf("\n\n'List is Empty'\nInsert some data and try again.");
    }

    else{
    struct node *seclast;
    if(head->next==NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
    else{
    for(temp=head;temp->next!=NULL;temp=temp->next){
    seclast=temp;
    }
    free(temp);
    seclast->next=NULL;
    }
    }
    return(head);
}

struct node *dltanypos(struct node *head)
{
    if(head==NULL){
    printf("\n\n'List is Empty'\nInsert some data and try again.");
    }
    else{
    struct node *prev;
    int pos,i=1;
    printf("\nEnter the position that you want to delete : ");
    scanf("%d",&pos);

    if(pos==1){
        temp=head;
        head=head->next;
        free(temp);
    }
    else{
    for(temp=head;i<pos;temp=temp->next,++i){
    prev=temp;
    }
    prev->next=temp->next;
    free(temp);
    }
    }
    return(head);    
}

struct node *traverse(struct node *head)
{
temp=head;
printf("\nThe linked list is : ");
if(head==NULL){
    printf("'EMPTY'\n");
}
else{
do
{
    printf("%d ",temp->data);
    temp=temp->next;
}   while(temp!=NULL);
}
}

struct node *sumofnode(struct node *head)
{
    if(head==NULL){
    printf("\n\n'List is Empty'\nInsert some data and try again.");
    }

    else{
    temp = head;
    int sum = 0;
    do
    {
        sum = sum + temp->data;
        temp = temp->next;
    } while (temp != NULL);
    printf("\nSum of all node is : %d", sum);
    }
}

struct node *search(struct node *head)
{
    if(head==NULL){
    printf("\n\n'List is Empty'\nInsert some data and try again.");
    }

    else{

    int data,total=1;
    printf("\nEnter the data that you want to search : ");
    scanf("%d",&data);
    for(temp=head;temp->next!=NULL;temp=temp->next){
        total++;
    }
    temp=head;
    for(int pos=1;pos<=total;++pos){
        if(data==temp->data){
            printf("\n'%d' is in position is : %d",data,pos);
            break;
        }
        else{
            temp=temp->next;
        }
        if(temp==NULL){
            printf("\n'No such data exists in the list.'");
            break;
        }
    }
    }
}

struct node *reverse(struct node *head){

    if(head==NULL){
    printf("\n\n'List is Empty'\nInsert some data and try again.");
    }

    else{
        struct node *prev=NULL,*curr=NULL;
        temp=head;
        while(temp!=NULL){
            prev=curr;
            curr=temp;
            temp=temp->next;
            curr->next=prev;
        }
        head->next=NULL;
        head=curr;
        printf("\n'The Link List is Successfully Reveresed'\n");
        return(head);
    }
}

void menu(int pick){
    printf("\n------------MENU-------------");
    while (1)
    {

        printf("\n\nChoose one task: \n");
        printf("\n0. Create list.\n");
        printf("\n1. Insert node at first.\n");
        printf("\n2. Insert node at last.\n");
        printf("\n3. Insert node at any position.\n");
        printf("\n4. Delete node at first.\n");
        printf("\n5. Delete node at last.\n");
        printf("\n6. Delete node at any position.\n");    
        printf("\n7. Display all nodes.\n");
        printf("\n8. Display sum of all nodes.\n");
        printf("\n9. Search the data in the list.\n"); 
        printf("\n10. Reverse the list.\n");
        printf("\n11. To exit\n");
        printf("\nEnter your choice:");
        scanf("%d", &pick);
        switch (pick)
        {
        case 0:
            h1=create(h1);
            break;
        case 1:
            h1=insertfirst(h1);
            break;
        case 2:
            h1=insertlast(h1);
            break;
        case 3:
            h1=insertanypos(h1);
            break;
        case 4:
            h1=dltfirst(h1);
            break;
        case 5:
            h1=dltlast(h1);
            break;
        case 6:
            h1=dltanypos(h1);
            break;
        case 7:
            traverse(h1);
            break;
        case 8:
            sumofnode(h1);
            break;
        case 9:
            search(h1);
            break;
        case 10:
            h1=reverse(h1);
            break;
        case 11:
            printf("\n'THANK YOU'\nDo Come And Run Again :)");
            exit(1);
            break;
        default:
            printf("\nIncorrect Choice\n\n'TRY AGAIN'");
        }
    }
}

int main()
{
    int n=-1;
    menu(n);
    return 0;
}