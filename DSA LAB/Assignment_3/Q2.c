#include<stdio.h> 
int RecursiveBsearch(int A[], int start, int end, int element) { 
   if(start>end) return -1; 
      int mid = (start+end)/2; 
   if( A[mid] == element ) return mid; 
   else if( element < A[mid] ) 
      RecursiveBsearch(A, start, mid-1, element); 
   else 
      RecursiveBsearch(A, mid+1, end, element); 
} 
int main() { 
   int A[] = {0,2,6,11,12,18,34,45,55,99}; 
   int n=55; 
   printf("%d is found at Index %d \n",n,RecursiveBsearch(A,0,9,n)); 
   return 0; 
} 