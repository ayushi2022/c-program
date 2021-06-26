#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
#define NILL -1
typedef struct queuetype
{
	int a[MAX];
	int front,rear;
}queue;
void main()
{
	int isfull(queue *);//it will check overflow
	int isempty(queue *);//it will check underflow
	void enqueue(queue *,int);//this function for insertion
	int delqueue(queue *);//this function for deletion
	queue Q;      //Q is object of structure queue
	Q.front=Q.rear=NILL;  //initially value of front and rear must be -1
	int ch,item;
	while(1)
	{
		printf("------------------------------MENU------------------------------\n");
		printf("\n1.Insert element in queue");
		printf("\n2.delete element from queue");
		printf("\n3.exit");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter element to insert");
				scanf("%d",&item);
				if(isfull(&Q))
				{
					printf("Queue is full");
				}
				else
				{
					enqueue(&Q,item);
				}
				break;
			case 2:
				if(isempty(&Q))
				{
					printf("Queue is empty");
				}
				else
				{
					item=delqueue(&Q);
					printf("deleted value is %d",item);
				}
				break;
			case 3:
				exit(1);
			default:
				printf("Invalid Number");
		}
	}
}
int isfull(queue *Q)
{
	if(Q->front==0 && Q->rear==MAX-1)
	   return 1;
	else
	   return 0;
}
int isempty(queue *Q)
{
	if(Q->front==NILL)
	   return 1;
	else
	   return 0;
}
void enqueue(queue *Q,int item)
{
	int i;
	if(Q->front==NILL)
	{
		Q->front=Q->rear=0;
	}
	else if(Q->rear==MAX-1)
	{
		for(i=Q->front;i<=Q->rear;i++)
		{
			Q->a[i   -   Q->front] = Q->a[i];
		}
		Q->rear=Q->rear - Q->front;
		Q->front=0;
		Q->rear=Q->rear+1;
	}
	else
	{
		Q->rear=Q->rear+1;
	}
	Q->a[Q->rear]=item;
}
int delqueue(queue *Q)
{
	int item;
	item=Q->a[Q->front];
	if(Q->front==Q->rear)
	   Q->front=Q->rear=NILL;
	else
	   Q->front=Q->front+1;
	return item;
}
