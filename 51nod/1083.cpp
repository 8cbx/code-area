#include<string.h>
#include<stdio.h>
#define max(a,b) a>b?a:b
int main()
{
    int a[510][510];
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                a[i][j]+=max(a[i-1][j],a[i][j-1]);
            }
        }
        printf("%d\n",a[n][n]);
    }
    return 0;
}
