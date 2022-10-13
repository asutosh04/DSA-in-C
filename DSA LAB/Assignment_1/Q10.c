#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the number of input char:");
    scanf("%d", &n);
    int offset;
    char temp;
    scanf("%c", &temp);
    char *input = (char *)malloc(n * sizeof(char));
    int numInt[n];
    printf("\nENTER THE CHAR\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &input[i]);
        numInt[i] = input[i];
        scanf("%c", &temp);
    }
    printf("Enter the offset (2/-2) : ");
    scanf("%d", &offset);
    for (int i = 0; i < n; i++)
    {
        int c = input[i] + offset;
        if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        {
            printf("%c ", c);
        }
        else if (c>90 && c<93)
        {
            int y = c - 26;
            printf("%c ",y);
        }
        else if (c < 65 || c < 97)
        {
            int x = 26 + c;
            printf("%c ", x);
        }
        else if (c>122)
        {
            int z = c - 26;
            printf("%c ",z);
        }
    }
    free(input);
    return 0;
}