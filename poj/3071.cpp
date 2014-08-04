#include<stdio.h>
#include<string.h>
int main()
{
    double dp[200][200];
    double ma[200][200];
    int n,m,i,j,k,x,y,z;
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        if(n==-1)
        {
            break;
        }
        m = 1<<n;
        for(i=0; i<m; i++)
        {
            dp[0][i]=1;
        }
        for(i=0; i<m; i++)
        {
            for(j=0; j<m; j++)
            {
                scanf("%lf",&ma[i][j]);
            }
        }
        for(i=1; i<=n; i++)
        {
            for(j=0; j<m; j++)
            {
                for(k=0; k<m; k++)
                {
                    x=k>>(i-1);
                    y=j>>(i-1);
                    if(x%2)
                    {
                        x--;
                        if(x==y)
                        {
                            dp[i][j]+=dp[i-1][j]*dp[i-1][k]*ma[j][k];
                        }
                    }
                    else
                    {
                        x++;
                        if(x==y)
                        {
                            dp[i][j]+=dp[i-1][j]*dp[i-1][k]*ma[j][k];
                        }
                    }
                }
            }
        }
        z=0;
        for(i=0;i<m;i++)
        {
            if(dp[n][z]<dp[n][i])
            {
                z=i;
            }
        }
        printf("%d\n",z+1);
    }
    return 0;
}
