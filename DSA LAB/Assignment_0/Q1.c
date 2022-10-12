#include <stdio.h>
void splitString(char s[100], int q, int flg, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '.')
        {
            flg = i;
            break;
        }
    }
    if (q == 0)
    {
        for (int j = 0; j < flg; j++)
        {
            printf("%c", s[j]);
        }
    }
    else if (q == 1)
    {
        for (int z = flg + 1; s[z] != '\0'; z++)
        {
            printf("%c", s[z]);
        }
    }
}

int main()
{
    char s[100];
    int q, flg;
    printf("Enter a string:");
    scanf("%s", s);
    printf("Enter the integer to print the specific.(0 or 1):");
    scanf("%d", &q);
    int n = sizeof(s) / sizeof(s[0]);
    splitString(s, q, flg, n);
    return 0;
}