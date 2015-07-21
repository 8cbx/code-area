#include<stdio.h>
#include<string.h>
#define max(a,b) (a>b?a:b)
int dp[150][10010];
int main()
{
    int n,w;
    int c[150],v[150];
    scanf("%d",&n);
    w=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
        v[i]=c[i];
        w+=v[i];
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(j>=2*c[i])
                dp[i][j]=max(dp[i-1][j],(dp[i-1][j-2*c[i]]+2*v[i]));
            else dp[i][j]=dp[i-1][j];
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }*/
    printf("%d\n",w-dp[n][w]);
    return 0;
}
