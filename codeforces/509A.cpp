#include<stdio.h>
#include<string.h>
int main()
{
    int a[15][15];
    int n,i,j;
    for(i=1;i<=15;i++)
    {
        a[i][1]=1;
        a[1][i]=1;
    }
    for(i=2;i<=10;i++)
    {
        for(j=2;j<=10;j++)
        {
            a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",a[n][n]);
    }
    return 0;
}
