#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the number of element in the array:");
    scanf("%d", &n);
    int *ptr = (int *)malloc(n * sizeof(int));
    printf("Enter the element of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    printf("The array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }
    int pos=n;
    ptr[pos - 1] = 0;
    printf("\nThe array after deleting\n");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d ", ptr[i]);
    }

    return 0;
}