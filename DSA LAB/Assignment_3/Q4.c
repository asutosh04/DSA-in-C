#include<stdio.h>
#include <stdlib.h>
 
int main()
{
 	int m, n, Total=0,count = 0;
  
 	printf("\n Please Enter Number of rows and columns for sparse matrix :  ");
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
            if(arr[i][j] == 0)
    		{
    			Total++;    		
			}
            if(arr[i][j]!=0){
                count++;
            }
        }
    }
  	if(Total > (m * n)/2)
  	{
    int **tri;
    tri=(int **)malloc((count+1)*sizeof(int *));
    for(int k=0;k<(count+1);k++){
        tri[k]=(int *)malloc(3*sizeof(int));
    }
    tri[0][0]=m;
    tri[0][1]=n;
    tri[0][2]=count;
    int k=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0){
                k++;
                tri[k][0]=i;
                tri[k][1]=j;
                tri[k][2]=arr[i][j];
            }
        }
    }
    printf("The sparse matrix you have entered is :\n");
  	for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    printf("The triplet of sparse matrix is :\n");
    for(int i=0;i<count+1;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",tri[i][j]);
        }
        printf("\n");
    }
    int tran[3][count+1];
    printf("The transpose of triplet is : \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<(count+1);j++){
            tran[i][j]=tri[j][i];
            printf("%d\t",tran[i][j]);
        }
        printf("\n");
    }
    
    if(count+1==3){
        printf("\nAddition of triplet and its transpose is :\n");
        int add[3][3];
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                add[i][j]=tri[i][j]+tran[i][j];
                printf("%d\t",add[i][j]);
            }
            printf("\n");
        }
    }
    else if(count+1!=3){
        printf("\nAddition not possible(Size not matching).");
    }

	}

	else
	{
		printf("\nError!!! The Matrix that you entered is Not a Sparse Matrix!");
	}
 	return 0;
}