#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 10
typedef enum {false, true} boolean;
typedef struct nodeType
{
   int info;
   struct nodeType *next;	
}node;
typedef struct
{
	node *front;
	node *rear;
}queue;
void createqueue(queue *);
boolean isEmpty(queue *);
void enqueue(queue *,int);
int dequeue(queue *);
void disposequeue(queue *);
void main()
{
	int choice,element;
	queue q;
	createqueue(&q);
	do
	{
		printf("\n-----------------menu-------------------");
		printf("\n1.Enter element in queue");
		printf("\n2.Delete element from queue");
		printf("\n3.peek");
		printf("\n4.Exit");
		printf("\nEnter your choice:  ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter value : ");
				scanf("%d",&element);
				enqueue(&q,element);
				break;
		    case 2:
		    	if(isEmpty(&q))
		    	{
		    		printf("queue is empty");
		    		printf("\nprint any key to continue........");
		    		getch();
				}
				else
				{
					printf("value deleted is %d \n",dequeue(&q));
					printf("print any key to continue........");
					getch();
				}
				break;
			case 3:
				if(isEmpty(&q))
				{
					printf("\nqueue is empty....");
					printf("\nprint any key to continue........");
					getch();
				}
				else
				{
					printf("1st element in queue is %d\n",peek(&q));
					printf("\nprint any key to continue........");
					getch();
				}
		}
	}
	while(choice != 4);
}
void createqueue(queue *pq)
{
	pq->front = pq->rear=NULL;
}
boolean isEmpty(queue *pq)
{
	return (pq->front == NULL ? true : false);
}
void enqueue(queue *pq,int value)
{
	node *ptr;
	ptr = (node *)malloc(sizeof(node));
	ptr->info = value;
	ptr->next = NULL;
	if(pq->rear == NULL)
	   pq->front = pq->rear = ptr;
	else
	{
		(pq->rear)->next = ptr;
		pq->rear = ptr;
	}
}
int dequeue(queue *pq)
{
	int temp;
	node *ptr;
	temp = (pq->front)->info;
	ptr = pq->front;
	if(pq->front == pq->rear)
	   pq->front = pq->rear = NULL;
	else
	   pq->front = (pq->front)->next;
	free(ptr);
	return temp;
}
int peek(queue *pq)
{
	return ( (pq->front)->info);
}
void disposequeue(queue *pq)
{
	node *ptr;
	while(pq->front != NULL)
	{
		ptr = pq->front;
		pq->front = (pq->front)->next;
		free(ptr);
	}
	pq->rear = NULL;
}

