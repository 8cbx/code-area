#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int add[105][105];
    int i,j,k;
    int n;
    int maxx=-9999999;
    int dp[105];
    while(scanf("%d",&n)!=EOF)
    {
        int maxx=-9999999;
        memset(add,0,sizeof(add));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&add[i][j]);
                add[i][j]+=add[i-1][j];
            }
        }
        /*printf("\n");
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                printf("%d",add[i][j]);
            }
            printf("\n");
        }*/
        for(i=1;i<=n;i++)
        {
            for(j=i;j<=n;j++)
            {
                memset(dp,0,sizeof(dp));
                for(k=1;k<=n;k++)
                {
                    if(dp[k-1]+add[j][k]-add[i-1][k]>=add[j][k]-add[i-1][k])
                    {
                        dp[k]=dp[k-1]+add[j][k]-add[i-1][k];
                    }
                    else dp[k]=add[j][k]-add[i-1][k];
                    if(dp[k]>maxx)
                        maxx=dp[k];
                }
                //printf("%d--%d\n",dp[n],maxx);

            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}
