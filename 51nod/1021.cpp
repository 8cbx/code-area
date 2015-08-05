#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,a[110],sum[110];
    int dp[110][110];
    scanf("%d",&n);
    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    memset(dp,0,sizeof(dp));
    for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            dp[i][j]=999999999;
            for(int k=i;k<j;k++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}
