//Write a C Program to implement binary search using recursion//
#include <stdio.h>
int binarysearch(int a[], int key, int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (a[mid] == key)
    {
        return mid;
    }
    if (key > a[mid])
    {
        return binarysearch(a, key, mid + 1, high);
    }
    else
    {
        return binarysearch(a, key, low, mid - 1);
    }
}
int main(){
    int arr[]={2,4,10,12,20};
    int search,element=-1;
    printf("\nArray is : ");
    for(int i=0;i<5;i++){
        printf("%d\t",arr[i]);
    }
printf("\nEnter the element you want to search : ");
scanf("%d",&search);
element = binarysearch(arr,search,0,5-1);

if(element == -1){
    printf("\nElement not found");
}
else{
    printf("\nElement '%d' found at index : %d",search,element);
}
return 0;
}
