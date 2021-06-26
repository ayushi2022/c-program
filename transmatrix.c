#include<stdio.h> 
#include<conio.h>
  void transpose(int a[4][4], int t[4][4]);   
  void main()                                     
  {
    int i, j;              
    int a[4][4], t[4][4];
    printf("enter matrix \n");
    for (i=0; i<4; i++)                       
      for (j=0; j<4; j++) 
	  {
        printf("Enter matrix element %d,%d: ", i, j);
        scanf("%d", &a[i][j]);
      }
    transpose(a, t); 
	                                   
    printf("Transpose of matrix  is :\n\n");
    for (i=0; i<4; i++) 
	{                
      for (j=0; j<4; j++)
        printf("%d ", t[i][j]);
      printf("\n");
    }
  }
  void transpose(int a[4][4], int t[4][4]) 
  {
    int row, col;          
    for (row=0; row<4; row++)
      for (col=0; col<4; col++)
        t[row][col] = a[col][row];

  }  

 

