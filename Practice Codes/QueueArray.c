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
    q->front=q->rear=-1;
    q->Q=(int *)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q, int x){
    if(q->rear==q->size-1){
        printf("Queue is full\n");
        return;
    }
    else{
        int d;
        printf("Enter the number you want to queue : ");
        scanf("%d",&d);
        x=d;
        q->rear=q->rear+1;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue *q){
    int num=-1;
    if(q->front==q->rear){
        printf("Queue is empty\n");
    }
    else{
        q->front=q->front+1;
        num=q->Q[q->front];
    }
    return num;
}

void display(struct Queue q){
    printf("Queue is : ");
    for(int i=q.front+1; i<=q.rear; i++){
        printf("%d ",q.Q[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    int data,n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    create(&q,n);
    enqueue(&q,data);
    enqueue(&q,data);
    enqueue(&q,data);
    display(q);
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
    display(q);
    return 0;
}