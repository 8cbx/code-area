#include<stdio.h>
#include<string.h>
int main()
{
    long long z[110][110];
    long long dp[110][110];
    int s1[110],s2[110];
    int i,j,k,l,n,m,coun;
    for(i=0;i<=101;i++)
    {
        z[i][0]=1;
    }
    for(i=1;i<101;i++)
    {
        for(j=1;j<=i;j++)
        {
            z[i][j]=(z[i-1][j-1]+z[i-1][j])%1000000009;
        }
    }
    while(scanf("%d%d%d",&n,&k,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%1d",&s1[i]);
        }
        for(i=1;i<=n;i++)
        {
            scanf("%1d",&s2[i]);
        }
        coun=0;
        for(i=1;i<=n;i++)
        {
            if(s1[i]!=s2[i])
            {
                coun++;
            }
        }
        memset(dp,0,sizeof(dp));
        dp[0][coun]=1;
        for(i=0;i<k;i++)
        {
            for(j=0;j<=n;j++)
            {
                for(l=0;l<=m;l++)
                {
                    if(j+m-2*l<0)
                    {
                        break;
                    }
                    if(j+m-2*l>n)
                    {
                        continue;
                    }
                    dp[i+1][j+m-2*l]=(dp[i+1][j+m-2*l]+(z[j][l]*z[n-j][m-l]%1000000009)*dp[i][j]%1000000009)%1000000009;
                }
            }
        }
        printf("%lld\n",dp[k][0]);
    }
    return 0;
}
