#include<stdio.h>
#include<string.h>
int dp[100010][15];
int pie[100010][15];
int main()
{
    int i,j,k;
    int n,t,w,maxx;
    int l,r,m;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        maxx=0;
        memset(dp,0,sizeof(dp));
        memset(pie,0,sizeof(pie));
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&w,&t);
            pie[t][w+1]++;
            if(t>maxx)
            maxx=t;
        }
        for(i=1;i<=11;i++)
        {
            dp[maxx][i]=pie[maxx][i];
        }
        for(i=maxx-1;i>=0;i--)
        {
            for(j=1;j<=11;j++)
            {
                l=dp[i+1][j-1]+pie[i][j];
                m=dp[i+1][j]+pie[i][j];
                r=dp[i+1][j+1]+pie[i][j];
                if(m>l)dp[i][j]=m;
                    else dp[i][j]=l;
                if(dp[i][j]<r)dp[i][j]=r;
            }
        }
        printf("%d\n",dp[0][6]);
    }
    return 0;
}
