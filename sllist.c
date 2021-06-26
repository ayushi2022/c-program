#include<stdio.h>
#include<stdlib.h>
typedef struct nodeType
{
	int info;
	struct nodeType *next;
}node;
void createemptylist(node **head);
void traverseinorder1(node *head);
void traverseinreverseorder2(node *head);
node *searchinunsortedlist(node *head, int item);
void auxilliarysearch(node *head,node **ploc,node **loc,int item);
void insertatbeginning(node **head, int item);
void insertafterelement(node *head,int item,int after);
void insertatend(node **head,int item);
void deletefrombeginning(node **head);
void deletefromend(node **head);
void deleteafterelement(node *head,int after);
void reverselist(node **head);
void deletelist(node **head);

void main()
{
	node *head;
	int choice, element, after;
	createemptylist(&head);
	while(1)
	{
		printf("            options available      \n");
		printf("+++++++++++++++++++++++++++++++++++++++++++\n");
		printf("1. Insert at beginning\n");
		printf("2. Insert at end\n");
		printf("3. Insert after a given element\n");
		printf("4. Traverse in order\n");
		printf("5. Traverse in reverse order\n");
		printf("6. Delete from beginning\n");
		printf("7. Delete from end\n");
		printf("8. Delete after a given element\n");
		printf("9. Reverse linked list\n");
		printf("10. Exit\n");
		printf("enter your choice (1-10): ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nenter element : ");
				scanf("%d",&element);
				insertatbeginning( &head,element);
				break;
			case 2:
				printf("\nenter element : ");
				scanf("%d",&element);
				insertatend( &head,element);
				break;
			case 3:
				printf("\nenter element : ");
				scanf("%d",&element);
				printf("\nenter element after which to insert : ");
				scanf("%d",&after);
				insertafterelement( head,element,after);
				break;
			case 4:
			    if(head == NULL)
				    printf("\n list is empty...");
				else
				   traverseinorder1( head);
				printf("\n\npress any key to continue....");
				getch();
				break;
			case 5:
			    if(head == NULL)
				    printf("\n list is empty...");
				else
				   traverseinreverseorder2( head);
				printf("\n\npress any key to continue....");
				getch();
				break;
			case 6:
				deletefrombeginning(&head);
				break;
			case 7:
				deletefromend(&head);
				break;
			case 8:
				printf("\nenter element after which to delete: ");
				scanf("%d",&after);
				deleteafterelement(head , after);
				break;
			case 9:
				reverselist(&head);
				break;
			case 10:
				deletelist(&head);
				exit(1);
			default:
			  printf("\nenter unvalid key");
			  break;		
		}
	}
}
void createemptylist(node **head)
{
	*head = NULL;
}
void traverseinorder1(node *head)
{
	while(head != NULL)
	{
		printf("%d\n",head->info);
		head = head->next;
	}
}
void traverseinreverseorder2(node *head)
{
	if(head->next != NULL)
	   traverseinreverseorder2(head->next);
	printf("%d\n",head->info);
}
node *searchinunsortedlist(node *head,int item)
{
	while((head != NULL) && (head->info != item))
	   head = head->next;
	return head;
}
node *searchinsortedlist(node *head, int item)
{
	while(head != NULL)
	{
		if(head->info == item)
		   return head;
		else if(item <head->info)
		   return NULL;
		else
		  head= head->next;
	}
	return NULL;
}
void auxilliarysearch(node *head, node **ploc, node **loc,int item)
{
	int flag=0;
	if(head == NULL)
	    *ploc = *loc = NULL;
	else if(head->info == item)
	{
		*ploc = NULL;
		*loc = head;
	}
	else 
	{
	   *ploc = head;
	   *loc = head->next;
	   while((*loc != NULL) && (!flag))
	   {
	     if((*loc)->info == item)
		    flag=1;
		 else
		 {
		 	*ploc = *loc;
		 	*loc = (*loc)->next;
		 }
			
	   }	
	}
}
void insertatbeginning(node **head, int item)
{
	node *ptr;
	ptr = (node *)malloc(sizeof(node));
	ptr->info = item;
	if(*head == NULL)
	   ptr->next = NULL;
	else
	  ptr->next = *head;
	*head = ptr;
}
void insertatend(node **head, int item)
{
	node *ptr,*loc;
	ptr = (node *)malloc(sizeof(node));
	ptr->info = item;
	ptr->next = NULL;
	if(*head == NULL)
	   *head = ptr;
	else
	{
		loc = *head;
		while(loc->next != NULL)
		  loc = loc->next;
		loc->next = ptr;
	} 
}
void insertafterelement(node *head,int item, int after)
{
	node *ptr,*loc;
	loc = searchinunsortedlist(head , after);
	if(loc == (node *) NULL)
	   return;
	ptr = (node *)malloc(sizeof(node));
	ptr->info = item;
	ptr->next = loc->next;
	loc->next = ptr;
}
void deletefrombeginning(node **head)
{
	node *ptr;
	if(*head == NULL)
	  return;
	else
	{
		ptr = *head;
		*head = (*head)->next;
		free(ptr);
	}
}
void deletefromend(node **head)
{
	node *ptr, *loc;
	if(*head == NULL)
	   return;
	else if((*head)->next == (node* ) NULL)
	{
		ptr = *head;
		*head = NULL;
		free(ptr);
	}
	else
	{
		loc = *head;
		ptr = (*head)->next;
		while(ptr->next != NULL)
		{
			loc = ptr;
			ptr = ptr->next;
		}
		loc->next = NULL;
		free(ptr);
	}
}
void deleteafterelement(node *head,int after)
{
	node *ptr,*loc;
	loc = searchinunsortedlist(head,after);
	if(loc == (node *) NULL)
	  return;
	ptr = loc->next;
	loc->next = ptr->next;
	free(ptr);
}
void reverselist(node **head)
{
	node *previousnode, *currentnode, *nextnode;
	currentnode = *head;
	nextnode = currentnode->next;
	previousnode = NULL;
	currentnode->next = NULL;
	while(nextnode != NULL)
	{
		previousnode = currentnode;
		currentnode = nextnode;
		nextnode = currentnode->next;
		currentnode->next = previousnode;
	}
	*head = currentnode;
}
void deletelist(node **head)
{
	node *ptr;
	while(*head != NULL)
	{
		ptr = *head;
		*head = (*head)->next;
		free(ptr);
	}
}
