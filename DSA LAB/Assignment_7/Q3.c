/*Write a C program to implement folding, division and mid-square techniques to
search an item using a Hash Table of size 11. Where the given array elements are:
20, 76, -5, 101, 63, 11, 86, 34, 54, 60*/

#include <stdio.h>
#include <stdlib.h>

void folding(int arr[],int hash[],int key)
{
            // folding
            int i, j, k, l, m,n,flag;
            for(int i=0; i<11; i++)
                {
                    hash[i] = -1;
                }
            for(int i=0; i<10; i++)
            {
                j = arr[i] % 10;
                k = arr[i] / 10;
                l = j + k;
                m = l % 11;
                if(hash[m] == -1)
                {
                    hash[m] = arr[i];
                }
                else
                {
                    // condition if collision happens
                    n = m;
                    while(hash[n] != -1)
                    {
                        n = (n + 1) % 11;
                    }
                    hash[n] = arr[i];
                }
            }
            flag = 0;
            for(int i=0; i<11; i++)
            {
                if(hash[i] == key)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
            {
                printf("The key is found");
            }
            else
            {
                printf("The key is not found");
            }
}

void division(int arr[],int hash[],int key)
{
            // Division
            for(int i=0; i<11; i++)
                {
                    hash[i] = -1;
                }
            int i, j, k, l, m,n,flag;
            for(int i=0; i<10; i++)
            {
                j = arr[i] % 11;
                if(hash[j] == -1)
                {
                    hash[j] = arr[i];
                }
                else
                {
                    // condition if collision happens
                    k = j;
                    while(hash[k] != -1)
                    {
                        k = (k + 1) % 11;
                    }
                    hash[k] = arr[i];
                }
            }
            flag = 0;
            for(int i=0; i<11; i++)
            {
                if(hash[i] == key)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
            {
                printf("The key is found");
            }
            else
            {
                printf("The key is not found");
            }
}

void midsquare(int arr[],int hash[],int key)
{
            // Mid-Square
            for(int i=0; i<11; i++)
                {
                    hash[i] = -1;
                }
            int i, j, k, l, m,n,flag;
            for(int i=0; i<10; i++)
            {
                j = arr[i] * arr[i];
                k = j % 100;
                l = k / 10;
                m = l % 11;
                if(hash[m] == -1)
                {
                    hash[m] = arr[i];
                }
                else
                {
                    // condition if collision happens
                    n = m;
                    while(hash[n] != -1)
                    {
                        n = (n + 1) % 11;
                    }
                    hash[n] = arr[i];
                }
            }
            flag = 0;
            for(int i=0; i<11; i++)
            {
                if(hash[i] == key)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
            {
                printf("The key is found");
            }
            else
            {
                printf("The key is not found");
            }
}

void menu(int arr[], int key)
{
    int choice,hash[11];
    while(1){
    printf("\n\t\tHashing Menu\t\t\n");
    printf(" \n0. Exit \n1. Folding \n2. Division \n3. Mid-Square \n");
    printf("Enter the choice of hashing technique: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            folding(arr,hash,key);
            break;
        case 2:
            division(arr,hash,key);
            break;
        case 3:
            midsquare(arr,hash,key);
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("Invalid choice");
    }
    }
}

int main()
{
    int key,arr[10]={20, 76, -5, 101, 63, 11, 86, 34, 54, 60};
    printf("Enter the key to be searched: ");
    scanf("%d", &key);
    menu(arr,key);
    return 0;
}