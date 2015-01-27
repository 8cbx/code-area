#include<stdio.h>
#include<string.h>
#define min(a,b) a>b?b:a
#define max(a,b) a>b?a:b
#define max3(a,b,c) a>b?(a>c?a:c):(b>c?b:c)
int dp[50010];
void print(int w)
{
    for(int i=0;i<=w;i++)
    {
        printf("%d ",dp[i]);
    }
    printf("\n");
}
int main()
{
    int w1[10010],v1[10010],w2[10010],v2[10010],r[10010];
    int w,n,i,j;
    while(scanf("%d%d",&w,&n)!=EOF)
    {
        w/=100;
        memset(dp,0,sizeof(dp));
        for(i=1; i<=n; i++)
        {
            scanf("%d%d%d%d%d",&w1[i],&v1[i],&w2[i],&v2[i],&r[i]);
            w1[i]/=100;
            w2[i]/=100;
        }
        for(i=1; i<=n; i++)
        {
            if(r[i]==1)
            {
                if(w>=w1[i]+w2[i])
                {
                    for(j=0; j<=w-w1[i]-w2[i]; j++)
                    {
                        dp[j]=max(dp[j+w1[i]+w2[i]]+v1[i]+v2[i],dp[j]);
                    }
                }
            }
            if(r[i]==2)
            {
                if(w>=w1[i]||w>=w2[i])
                {
                    int minn=min(w1[i],w2[i]);
                    for(j=0; j<=w-minn; j++)
                    {
                        int temp1,temp2;
                        temp1=0;
                        temp2=0;
                        if(j+w1[i]<=w)
                        {
                            temp1=dp[j+w1[i]]+v1[i];
                        }
                        if(j+w2[i]<=w)
                        {
                            temp2=dp[j+w2[i]]+v2[i];
                        }
                        dp[j]=max3(temp1,temp2,dp[j]);
                    }
                }
            }
            if(r[i]==3)
            {
                if(w>=w1[i]+w2[i]||w>=w1[i])
                {
                    for(j=0; j<=w-w1[i]; j++)
                    {
                        int temp1,temp2;
                        temp1=0;
                        temp2=0;
                        if(j+w1[i]<=w)
                        {
                            temp1=dp[j+w1[i]]+v1[i];
                        }
                        if(j+w1[i]+w2[i]<=w)
                        {
                            temp2=dp[j+w1[i]+w2[i]]+v1[i]+v2[i];
                        }
                        dp[j]=max3(temp1,temp2,dp[j]);
                    }
                }
            }
        }
        printf("%d\n",dp[0]);
    }
    return 0;
}
