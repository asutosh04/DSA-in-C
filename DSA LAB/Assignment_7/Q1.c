//Write a C Program to implement linear search using recursion//
#include <stdio.h>
#include <stdlib.h>
size_t linearSearch(const int array[], int key, size_t size)
{
    if(size == 0){
        return -1;
    }
    else if(key == array[size-1]){
        return size-1;
    }
    else{
        return linearSearch(array, key, size-1);
    }
}

int main(){
int n,*arr,search,element=-1;
printf("Enter the array size : ");
scanf("%d",&n);
arr=(int *)malloc(n*sizeof(int));
for(int i=0;i<n;i++){
    printf("Enter the %d element : ",i+1);
    scanf("%d",&arr[i]);
}
printf("Enter the element you want to search : ");
scanf("%d",&search);
element = linearSearch(arr, search, n);

if(element == -1){
    printf("Element not found");
}
else{
    printf("Element '%d' found at index : %d",search,element);
}
return 0;
}
