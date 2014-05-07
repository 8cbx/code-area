#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,i,j;
    int w[4000],d[4000],dp[13000];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&w[i],&d[i]);
        }
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            for(j=m;j-w[i]>=0;j--)
            {
                if(dp[j-w[i]]+d[i]>dp[j])
                {
                    dp[j]=dp[j-w[i]]+d[i];
                }
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
