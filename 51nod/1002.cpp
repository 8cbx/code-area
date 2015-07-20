#include<stdio.h>
#include<string.h>
#define max(a,b) a>b?a:b
int main()
{
    int a[510][510];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            a[i][j]+=max(a[i-1][j],a[i-1][j-1]);
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }*/
    int maxx=0;
    for(int i=1;i<=n;i++)
    {
        if(maxx<a[n][i])
        {
            maxx=a[n][i];
        }
    }
    printf("%d\n",maxx);
    return 0;
}
