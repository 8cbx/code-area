#include<stdio.h>
#include<string.h>
int main()
{
    long long a[40][40];
    for(int i=0;i<=35;i++)
    {
        a[i][0]=1LL;
    }
    for(int i=1;i<=35;i++)
    {
        for(int j=1;j<=35;j++)
        {
            if(j==i)
            {
                a[i][j]=a[i][j-1];
            }
            else a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }
    int n;
    int cases=0;
    while(scanf("%d",&n)!=EOF)
    {
        cases++;
        if(n==-1)
        {
            break;
        }
        else
        {
            printf("%d %d %lld\n",cases,n,a[n][n]*2);
        }
    }
    return 0;
}
