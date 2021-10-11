//Name: Suzan Dsouza
//R.No: 9194
//Circular queue implementation with counter
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct cqueue
{
    int a[SIZE];
    int front,rear,count;   //counter to count no of elements

};

void cequeue(struct cqueue*p,int x)
{
    if(p->count==SIZE)  //if queue is full
    //if((p->rear+1)%SIZE==p->front)
    printf("Queue Overflow\n");
    else{
        p->rear=(p->rear+1)%SIZE;
        p->a[p->rear]=x;
        p->count++;
        if(p->front==-1)
        p->front=0;
    }
}
int cdequeue(struct cqueue *p)
{
    int x;
    if(p->count==0)        //queue is empty
    {
        printf("Queue Underflow\n");
        return 0;
    }
    else{
        x=p->a[p->front];
        p->count--;
        if(p->front==p->rear)
        p->front=p->rear=-1;
        else
        p->front=(p->front+1)%SIZE;
        return x;
    }
}
void cdisplay(struct cqueue *p)
{
    int i=p->front;
    if(p->front==-1)
    printf("No elements to display\n");
    else{
        do{
            printf("%d\t",(p->a[i]));
            i=(i+1)%SIZE;
        }while(i!=(p->rear+1)%SIZE);
    }
}
int main()
{
    struct cqueue cq;
    int x,y,choice;
    cq.front=0;
    cq.front=-1;
    cq.rear=-1;
    do{
        printf("Enter the choice 1.Push 2. Remove 3.Display 4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter element to be added");
            scanf("%d",&x);
            cequeue(&cq,x);
            break;
            
            case 2:
            y=cdequeue(&cq);
            printf("The removed element is :%d",y);
            break;
            case 3: 
            cdisplay(&cq);
            break;
        }
    }
    while(choice!=4);


    return 0;
}