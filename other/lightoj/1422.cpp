#include<stdio.h>
#include<string.h>
#define min(a,b) a<b?a:b
int main()
{
    int a[110];
    int dp[110][110];
    int n,i,j,k,task,times;
    times=1;
    scanf("%d",&task);
    while(task--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            dp[i][i]=1;
        }
        for(i=n-1;i>=1;i--)
        {
            for(j=i+1;j<=n;j++)
            {
                dp[i][j]=dp[i+1][j]+1;
                for(k=i+1;k<=j;k++)
                {
                    if(a[k]==a[i])
                    {
                        dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k][j]);
                    }
                }
            }
        }
        printf("Case %d: %d\n",times,dp[1][n]);
        times++;
    }
    return 0;
}
