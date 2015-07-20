#include<stdio.h>
#include<string.h>
#define max(a,b) (a>b?a:b)
int dp[50010];
int main()
{
    int nn,w;
    int c[150],v[150],n[150];
    scanf("%d%d",&nn,&w);
    for(int i=1; i<=nn; i++)
    {
        scanf("%d%d%d",&c[i],&v[i],&n[i]);
    }
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=nn; i++)
    {
        int k,t;
        k=1;
        t=n[i];
        while(t>k)
        {
            for(int j=w; j>=c[i]*k; j--)
            {
                dp[j]=max(dp[j],(dp[j-c[i]*k]+v[i]*k));
            }
            t-=k;
            k*=2;
        }
        for(int j=w; j>=c[i]*t; j--)
        {
            dp[j]=max(dp[j],(dp[j-c[i]*t]+v[i]*t));
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
    printf("%d\n",dp[w]);
    return 0;
}
