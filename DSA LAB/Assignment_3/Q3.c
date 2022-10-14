#include<stdio.h>
#include<stdlib.h>
 
int main()
{
 	int m, n, Total = 0;
  
 	printf("\n Please Enter Number of rows and columns  :  ");
 	scanf("%d %d", &m, &n);
 
    int **arr;
    arr = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    printf("\nEnter the element of the matrix\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\nEnter the element arr[%d][%d] : ",i,j);
            scanf("%d", &arr[i][j]);
        }
    }
 	for(int i = 0; i < m; i++)
  	{
   		for(int j = 0; j < n; j++)
    	{
    		if(arr[i][j] == 0)
    		{
    			Total++;    		
			}
   	 	}
  	}
  	if(Total > (m * n)/2)
  	{
  		printf("\n The Matrix that you entered is a Sparse Matrix ");
	}
	else
	{
		printf("\n The Matrix that you entered is Not a Sparse Matrix ");
	}
  	
 	return 0;
}