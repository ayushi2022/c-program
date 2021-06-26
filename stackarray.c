#include<stdio.h>
#include<stdlib.h>
# define NILL -1
# define MAX 5
typedef struct stacktype
{
	int a[MAX];
	int top;
}STACK;
void main()
{
	STACK S;
	S.top=NILL; //initilize top of stack
	void push(STACK *,int); //to add a new element
	int pop(STACK *); //to remove the last entering element
	int peep(STACK *); //to show the top element of stack
	int isoverflow(STACK *);// to check stack is full or not
	int isunderflow(STACK *); //to check stack is empty or not
	int ch,item;
	while(1)
	{
		printf("---------------Menu--------------");
		printf("\n");
		printf("\n 1.Push"); 
		printf("\n 2.Pop");
		printf("\n 3.Peep");
		printf("\n 4.Exit");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:

				if(isoverflow(&S))
				{
					printf("STACK is full\n");
				}
				else
				{
					printf("enter elememt to push");
				    scanf("%d",&item);
					push(&S,item);
				}
				break;
			case 2:
				if(isunderflow(&S))
				{
				     printf("stack is empty\n");	
				}
				else
				{
					item=pop(&S);
					printf("poped value is %d",item);
				}
				break;
			case 3:
				if(isunderflow(&S))
				{
					printf("stack is empty\n");
				}
				else
				{
					item=peep(&S);
					printf("Peep value is %d",item);
				}
				break;
			case 4:
				exit(1);
			default:
				printf("enter wrong choice\n");
		}
	}
}
int isoverflow(STACK *S)
{
	if(S->top==MAX-1)
	   return 1;
	else
	   return 0;
}
int isunderflow(STACK *S)
{
	if(S->top==NILL)
	  return 1;
	else
	  return 0;
}
void push(STACK *S,int item)
{
	S->top=S->top+1;
	S->a[S->top]=item;
}
int pop(STACK *S)
{
	int item;
	item=S->a[S->top];
	S->top=S->top-1;
	return item;
}
int peep(STACK *S)
{
	int item;
	item=S->a[S->top];
	return item;
}
