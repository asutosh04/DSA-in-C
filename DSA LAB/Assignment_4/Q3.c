/*Q3-Write a C program to subtract two given polynomials using an array*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int hd1, hd2;
    printf("Enter the order of first polynomial:");
    scanf("%d", &hd1);
    printf("Enter the order of second polynomial:");
    scanf("%d", &hd2);
    int hd;
    if (hd1 > hd2)
    {
        hd = hd1;
    }
    else
    {
        hd = hd2;
    }
    int *poly = (int *)calloc((hd + 1), sizeof(int));
    printf("\nFIRST POLYNOMIAL\n");
    for (int i = 0; i <= hd1; i++)
    {
        printf("Enter the coefficient of X^%d:", i);
        scanf("%d", &poly[i]);
    }
    printf("\n\n");
    int *poly1 = (int *)calloc((hd + 1), sizeof(int));
    printf("\nSECOND POLYNOMIAL\n");
    for (int i = 0; i <= hd2; i++)
    {
        printf("Enter the coefficient of X^%d:", i);
        scanf("%d", &poly1[i]);
    }
    int *polysub = (int *)calloc((hd + 1), sizeof(int));
    for (int i = 0; i <= hd; i++)
    {
        if (hd1 > hd2)
        {
            polysub[i] = poly[i] - poly1[i];
        }
        else
        {
            polysub[i] = poly1[i] - poly[i];
        }
    }
    printf("\nFINAL POLYNOMIAL AFTER SUBSTRACTION\n");
    for (int i = hd; i >= 0; i--)
    {
        if (i != 0)
        {
            printf("%dX^%d+", polysub[i], i);
        }
        else
        {
            printf("%dX^%d", polysub[i], i);
        }
    }
    return 0;
}