#include <stdio.h>
#include <stdlib.h>

void main()
{
    int mx , mn , n , *arr1;
    printf("Input the number of elements to be stored in the array : ");
    scanf("%d",&n);
    arr1=(int*)malloc(n*sizeof(int));
 
    printf("Input %d elements in the array :\n",n);
    for(int i=0;i<n;i++)
      {
        printf("Element - %d : ",i+1);
        scanf("%d",&arr1[i]);
      }

    mx = arr1[0];
    mn = arr1[0];

    for(int j=1; j<n; j++)
    {
        if(arr1[j]>mx)
        {
          mx = arr1[j];
        }

        if(arr1[j]<mn)
        {
          mn = arr1[j];
        }
    }
    printf("Maximum element is : %d\n", mx);
    printf("Minimum element is : %d\n\n", mn);
}