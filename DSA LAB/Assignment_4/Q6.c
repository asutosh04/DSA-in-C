#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void insertfirst()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
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
}

void insertlast()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data which you want to insert : ");
    scanf("%d", &new_node->data);
    new_node->next=NULL;
    if (head == NULL)
        head = new_node;
    else
    {
        struct node *temp = NULL;
        for (temp = head; temp->next != NULL; temp = temp->next)
            ;
        temp->next = new_node;
        new_node->next=NULL;
    }
}

void insertanypos()
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
        struct node *temp = NULL;
        if(pos==1){
            temp=head;
            head=new_node;
            new_node->next=temp;
        }
        else{
        int i = 1;
        for (temp = head; i < pos - 1; temp = temp->next, ++i);
        struct node *temp1 = temp->next;
        temp->next = new_node;
        new_node->next = temp1;
        }
    }
}

void dltfirst()
{
    if(head==NULL){
        printf("\n\n'List is Empty'\nInsert some data and try again!");
    }
    else{
    struct node *temp=head;
    head=temp->next;
    free(temp);
    }
}

void dltlast()
{
    if(head==NULL){
    printf("\n\n'List is Empty'\nInsert some data and try again.");
    }

    else{
    struct node *temp=NULL,*seclast;
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
    }
}

void dltanypos()
{
    if(head==NULL){
    printf("\n\n'List is Empty'\nInsert some data and try again.");
    }
    else{
    struct node *temp=NULL,*prev;
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
}

void traverse()
{
struct node *temp=head;
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

void sumofnode()
{
    if(head==NULL){
    printf("\n\n'List is Empty'\nInsert some data and try again.");
    }

    else{
    struct node *temp = head;
    int sum = 0;
    do
    {
        sum = sum + temp->data;
        temp = temp->next;
    } while (temp != NULL);
    printf("\nSum of all node is : %d", sum);
    }    
}

void search()
{
    if(head==NULL){
    printf("\n\n'List is Empty'\nInsert some data and try again.");
    }

    else{
    struct node *temp;
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

int main()
{
    struct node *list,*temp;
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
    int pick;
    printf("\nMENU\n");
    printf("\nChoose one task: \n");
    printf("\n1. Insert node at first.\n");
    printf("\n2. Insert node at last.\n");
    printf("\n3. Insert node at any position.\n");
    printf("\n4. Delete node at first.\n");
    printf("\n5. Delete node at last.\n");
    printf("\n6. Delete node at any position.\n");    
    printf("\n7. Display all nodes.\n");
    printf("\n8. Display sum of all nodes.\n");
    printf("\n9. Search the data in the list.\n"); 
    printf("\n10. To exit\n");
    printf("\nEnter your choice:");
    while (1)
    {
        scanf("%d", &pick);
        switch (pick)
        {
        case 1:
            insertfirst();
            break;
        case 2:
            insertlast();
            break;
        case 3:
            insertanypos();
            break;
        case 4:
            dltfirst();
            break;
        case 5:
            dltlast();
            break;
        case 6:
            dltanypos();
            break;
        case 7:
            traverse();
            break;
        case 8:
            sumofnode();
            break;
        case 9:
            search();
            break;
        case 10:
            printf("\n'THANK YOU'\nDo Come And Run Again :)");
            for (temp=head;temp!=NULL;temp=temp->next){
                free(temp);
            }
            free(head);
            free(list);
            exit(1);
            break;
        default:
            printf("\nIncorrect Choice\n\n'TRY AGAIN'");
        }
        printf("\n\n1. Insert node at first.\n");
        printf("\n2. Insert node at last.\n");
        printf("\n3. Insert node at any position.\n");
        printf("\n4. Delete node at first.\n");
        printf("\n5. Delete node at last.\n");
        printf("\n6. Delete node at any position.\n");    
        printf("\n7. Display all nodes.\n");
        printf("\n8. Display sum of all nodes.\n");
        printf("\n9. Search the data in the list.\n");        
        printf("\n10. To exit.\n");
        printf("\nEnter your choice:");
    }
    return 0;
}