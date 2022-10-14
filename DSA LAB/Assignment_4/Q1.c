/*Q1-Write a C program to represent a given polynomial using an array
anx^n+....+a1x+a0=0*/

#include<stdio.h>

int main()
{
int n;
printf("Enter the degree of polynomial : ");
scanf("%d", &n);
int A[n];
printf("\nEnter the coefficient of polynomial : \n");
for(int i = n; i >= 0; i--)
{
 printf("Enter the coefficient of x^%d : ", i);
 scanf("%d", &A[i]);
}
printf("The polynomial is : ");
for(int i = n; i >= 0; i--)
{
  if(i != 1 && i != 0)
  {
   printf("%dx^%d + ",A[i],i);
  }
  else if(i == 1)
  {
   printf("%dx + ",A[i]);
  }
  else
  {
   printf("%d", A[i]);
 }
}
return 0;
}

