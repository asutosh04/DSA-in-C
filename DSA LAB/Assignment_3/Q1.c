#include <stdio.h>
#include <stdlib.h>
int binarysearch(int arr[], int n, int search)
{
    int first, last, middle;
    first = 0;
    last = n - 1;
    middle = (first + last) / 2;

    while (first <= last)
    {
        if (arr[middle] < search)
            first = middle + 1;
        else if (arr[middle] == search)
        {
            printf("%d found at location %d after sorting.\n", search, middle + 1);
            break;
        }
        else
            last = middle - 1;

        middle = (first + last) / 2;
    }
    if (first > last)
        printf("Not found! %d isn't present in the list.\n", search);
}
int main(){
    int c,first,last,middle,n,search;
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    int *arr;
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter %d integers:\n", n);
    for (c = 0; c < n; c++)
    scanf("%d", &arr[c]);
    printf("Enter value to find:\n");
    scanf("%d", &search);
    for (int i = 0; i < n; ++i) 
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] > arr[j]) 
            {
                int a =  arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
    printf("\n------------Using user defined function--------------\n");
    binarysearch(arr, n, search);
    return 0;
}
