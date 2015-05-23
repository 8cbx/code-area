#include<stdio.h>
#include<string.h>
int maxx(int a,int b,int k)
{
    if(a>=b&&a<=k)
    {
        return a;
    }
    else
    {
        if(b>=a&&b<=k)
        {
            return b;
        }
        else return 0;
    }
}
int max(int a,int b,int c,int d,int k)
{
    return maxx(maxx(a,b,k),maxx(c,d,k),k);
}
int maz[150][150];
int dp[150][150][150];
int main()
{
    int n,m,k;
    //int maxxx;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        //maxxx=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&maz[i][j]);
            }
        }
        memset(dp,-1,sizeof(dp));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                dp[i][j][0] = 1;
                if(maz[i][j] <= k) dp[i][j][maz[i][j]] = 1;
                for(int kk=0; kk<=k; kk++)
                {
                    if(dp[i][j][kk]==-1)
                    {
                        continue;
                    }
                    if(i<n)
                    {
                        dp[i+1][j][kk]=1;
                        if(kk+maz[i+1][j]<=k)
                        {
                            dp[i+1][j][kk+maz[i+1][j]]=1;
                        }
                    }
                    if(j<m)
                    {
                        dp[i][j+1][kk]=1;
                        if(kk+maz[i][j+1]<=k)
                        {
                            dp[i][j+1][kk+maz[i][j+1]]=1;
                        }
                    }
                }
            }
            //printf("\n");
        }
        int flag=0;
        for(int i=0; i<=k; i++)
        {
            if(dp[n][m][i]!=-1)
            {
                if(i>flag)
                {
                    flag=i;
                }
            }
        }
        printf("%d\n",flag);
    }
    return 0;
}
