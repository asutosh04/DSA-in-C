#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("No list exisst!!!");
    }
    else
    {
        struct node *check;
        check=head;
        do
        {
            printf("%d\t",check->data);
            check=check->next;
        } while (check!=NULL);

    }
}

void concatenate(struct node *head1, struct node *head2)
{
    if (head1 != NULL && head2 != NULL)
    {
        if (head1->next == NULL)
            head1->next = head2;
        else
            concatenate(head1->next, head2);
    }
    else
    {
        printf("Either head1 or head2 is NULL\n");
    }
}
int main()
{
    struct node *temp, *head1, *head2, *list1, *list2;
    int n, i;
    printf("Enter the number of elements in list1 : ");
    scanf("%d", &n);
    head1 = NULL;
    for (i = 0; i < n; i++)
    {
        list1 = malloc(sizeof(struct node));
        printf("Enter the data of node %d : ",i+1);
        scanf("%d", &list1->data);
        list1->next = NULL;
        if (head1 == NULL)
            head1 = list1;
        else
            temp->next = list1;
            temp = list1;
    }
    printf("Enter the number of elements in list2 : ");
    scanf("%d", &n);
    head2 = NULL;
    for (i = 0; i < n; i++)
    {
        list2 = malloc(sizeof(struct node));
        printf("Enter the data of node %d : ",i+1);
        scanf("%d", &list2->data);
        list2->next = NULL;
        if (head2 == NULL)
            head2 = list2;
        else
            temp->next = list2;
        temp = list2;
    }
    concatenate(head1, head2);
    printf("\nConcatenated Linkedlist:\n");
    display(head1);
    return 0;
}