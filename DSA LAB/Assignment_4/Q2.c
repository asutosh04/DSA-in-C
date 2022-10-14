/*Q2-Write a C program to add two given polynomials using an array*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int p1, p2;
    printf("Enter the order of first polynomial:");
    scanf("%d", &p1);
    printf("Enter the order of second polynomial:");
    scanf("%d", &p2);
    int p;
    if (p1 > p2)
    {
        p = p1;
    }
    else
    {
        p = p2;
    }
    int *plnm1 = (int *)calloc((p + 1) , sizeof(int));
    printf("\nFIRST POLYNOMIAL\n");
    for (int i = 0; i <= p1; i++)
    {
        printf("Enter the coefficient of X^%d:", i);
        scanf("%d", &plnm1[i]);
    }
    printf("\n\n");
    int *plnm2 = (int *)calloc((p + 1) , sizeof(int));
    printf("\nSECOND POLYNOMIAL\n");
    for (int i = 0; i <= p2; i++)
    {
        printf("Enter the coefficient of X^%d:", i);
        scanf("%d", &plnm2[i]);
    }
    if (p1 > p2)
    {
        plnm2[p] = 0;
    }
    else
    {
        p = p2
;
        plnm1[p] = 0;
    }
    int *psum = (int *)calloc((p + 1) , sizeof(int));
    for (int i = 0; i <= p; i++)
    {
        psum[i] = plnm1[i] + plnm2[i];
    }

    printf("\nFINAL POLYNOMIAL AFTER SUM\n");
    for (int i = p; i >= 0; i--)
    {
        printf("Coefficient of X^%d:%d\n", i, psum[i]);
    }

    return 0;
}