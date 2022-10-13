#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, val;
    printf("Enter the number of element in the array:");
    scanf("%d", &n);
    int *ptr = (int *)malloc((n + 1) * sizeof(int));
    printf("Enter the element of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    printf("The array is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }
    int pos=n+1;
    printf("\nEnter the value you want to insert:");
    scanf("%d", &val);
    ptr[pos - 1] = val;
    printf("\nThe array after inserting is : \n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", ptr[i]);
    }

    return 0;
}