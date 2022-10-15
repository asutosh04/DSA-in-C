#include <stdio.h>
#include <math.h>

int checkprime(int p){
    int i, flag = 1;
    int t = p / 2;
    for (i = 2; i <= t; ++i)
    {
        if (p % i == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int gcd(int x, int p)
{
    while (x != p)
    {
        if (x > p)
        {
            x = x - p;
        }
        else
        {
            p = p - x;
        }
    }
    if (x == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int power(int x, int a){
    int ans=pow(x,a);
    return ans;
}

int main()
{
    int x, a, p, res,rem;
    printf("Enter the vlaues of x,a,p:");
    scanf("%d %d %d", &x, &a, &p);
    int gflag, pflag;
    gflag = gcd(x, p);
    pflag = checkprime(p);
    if (gflag == 1 && pflag == 1 && a > (p))
    {
        rem=a%p;
        res=power(x,rem);
        if(rem==0)
        printf("The result is %d",res);
        else
        printf("The result is %d",res);
    }
    else
    {
        printf("Requirement not met !!");
    }
    return 0;
}