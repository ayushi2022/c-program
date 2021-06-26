#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct dlklist
{
	struct dlklist *prev;
	int info;
	struct dlklist *next;
}node;
void main()
{
	node *head,*tail;
	head=tail=NULL;
	int ch,data;
	node *ptr,*loc,*temp;
	while(1)
	{
		printf("1. Insert at begning");
		printf("\n2.Insert at end ");
		printf("\n3.Traversing");
		printf("\n4.Traverse in rev order");
		printf("\n5.Exit\n");
		printf("enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
//			case 1:
//				printf("enter the data to be insert");
//				scanf("%d",&data);
//				ptr=(node *)malloc(sizeof(node)); //new node
//				ptr->next=NULL;
//				ptr->prev=NULL;
//				ptr->info=data;
//				if(head=NULL)
//				{
//				    head=ptr;
//					tail=ptr;	
//				}
//				else
//				{
//					ptr->next=head;
//					head->prev=ptr;
//					head=ptr;
//				}
//				break;
            case 1:
				printf("enter value :");
				scanf("%d",&data);
				ptr = (node *)malloc(sizeof(node));
				ptr->info=data;
				ptr->next=NULL;
				ptr->prev=NULL;
				if(head==NULL)
				{
				    head=ptr; //head will start to pointer
				    tail=ptr;
			    }
			    else
			    {
			        ptr->next=head;
			        head->prev=ptr;
			        head=ptr;
			    }
				break;
			case 2:
				printf("enter the data to be insert");
				scanf("%d",&data);
				ptr = (node *)malloc(sizeof(node)); //new node
				ptr->info=data;
				ptr->next=NULL;
				ptr->prev=NULL;
				
				if(head=NULL)
				{
				    head=ptr;
					tail=ptr;	
				}
				else
				{
					tail->next=ptr;
					ptr->prev=tail;
					tail=ptr;
				}
				break;
//			case 3:
//				loc=head;
//				while(loc!=NULL)
//				{
//					printf("%d->",loc->info);
//					loc=loc->next;
//				}
//				break;
            case 3:
				while(head!=NULL)
				{
					printf("%d->",head->info);
					head=head->next;
				}
				break;
			case 4:
				loc=tail;
				while(loc!=NULL)
				{
					printf("%d->",loc->info);
					loc=loc->prev;
				}
				break;
			case 5:
				exit(1);
			default:
				printf("wrong choice");
		}
		getch();
	}
	
}
