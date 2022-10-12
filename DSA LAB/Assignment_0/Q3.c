#include <stdio.h>
void SubSeq(char s[], int n)
{
    int subset = (1 << n);
    for (int mask = 0; mask < subset; mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) != 0)
            {
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }
}
int main()
{
    char str[100];
    printf("Enter the string:");
    scanf("%s", str);
    int n;
    for (n = 0; str[n] != '\0'; n++)
        ;
    SubSeq(str, n);

    return 0;
}