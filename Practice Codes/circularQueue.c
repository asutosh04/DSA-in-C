#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size){
    q->size=size;
    q->front=q->rear=0;
    q->Q=(int *)malloc(q->size*sizeof(int));
    printf("\nQueue created successfully.\n");
}

void enqueue(struct Queue *q){
    if((q->rear+1)%q->size==q->front){
        printf("Queue is full\n");
        return;
    }
    else{
        int data;
        printf("Enter the number you want to queue : ");
        scanf("%d",&data);
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=data;
    }
}

int dequeue(struct Queue *q){
    int num=-1;
    if(q->front==q->rear){
        printf("\nQueue is empty\n");
    }
    else{
        q->front=(q->front+1)%q->size;
        num=q->Q[q->front];
    }
    if(num==-1){
        printf("\nNo Elements Deleted.\n");
    }
    else{
        return num;
    }
}

void traverse(struct Queue q){
    printf("Queue is : ");
    int i=q.front+1;
    do{
        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;
    } while(i!=(q.rear+1)%q.size);
    printf("\n");
}

int main()
{
    struct Queue q;
    int size,choice;
    while(1)
    {
        printf("\n\t\tCIRCULAR QUEUE MENU\t\t\n");
        printf("\n0.Create\n");
        printf("\n1.Enqueue\n");
        printf("\n2.Dequeue\n");
        printf("\n3.Traverse\n");
        printf("\n4.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            printf("\nEnter the size of the queue : ");
            scanf("%d",&size);
            create(&q,size);
            break;
        case 1:
            enqueue(&q);
            break;
        case 2:
            printf("\nDeleted element is  %d\n",dequeue(&q));
            break;
        case 3:
            traverse(q);
            break;
        case 4:
            exit(1);
        default:
            printf("\nWrong choice\n");
        }/*End of switch*/
    }/*End of while*/

    return 0;
}