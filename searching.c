#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int linearsearch(int [],int ,int );
	int binarysearch(int a[],int ,int ,int);
	int item,index,ch;
	printf("\n-----------Menu-----------");
	printf("\n1.linear search");
	printf("\n2.binary search");
	printf("\nEnter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("enter an element to search");
			scanf("%d",&item);
			index=linearsearch(a,9,item);
			if(index==-1)
			   printf("element not found");
			else
			 printf("element found at %d position",index+1);
			break;
		case 2:
			printf("enter an element to search");
			scanf("%d",&item);
			index=binarysearch(a,0,9,item);
			if(index==-1)
			   printf("element not found");
			else
			 printf("element found at %d position",index+1);
			break;
		default:
			printf("Invalid number");
	}
}
int linearsearch(int a[],int n,int item)
{
  int k;
	for(k=0;k<n;k++)
	{
		if(a[k]== item)
		  return k;
	}
	return -1;	
}
int binarysearch(int a[],int lb,int ub,int item)
{
	int mid;
	while(lb <= ub)
	{
	    mid = (lb + ub)/2;
	    if(item == a[mid])
	      return mid;
	    else if(item<a[mid])	
	       ub = mid-1;
	    else if(item>a[mid])
	      lb = mid +1;
	}
	return -1;
}


