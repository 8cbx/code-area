#include<stdio.h>
#include<string.h>
int main()
{
    long long dp[15][1<<15];
    int s[1<<15];
    int mapp[15];
    int n,m,temp;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(mapp,0,sizeof(mapp));
        memset(dp,0,sizeof(dp));
         memset(s,0,sizeof(s));
         int tot=0;
         tot++;
        for(int i=0; i<(1<<m); i++)
        {
            if((i&(i<<1))==0)
            {
                s[tot]=i;
                tot++;
                //printf("%d\n",i);
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&temp);
                if(temp==0)
                {
                    mapp[i]|=(1<<(m-j));
                }
            }
        }
        for(int i=0; i<=tot; i++)
        {
            if((s[i]&mapp[1])==0)
            {
                dp[1][s[i]]=1;
            }
        }
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<tot; j++)
            {
                if((s[j]&mapp[i])==0)
                {
                    for(int k=1; k<tot; k++)
                    {
                        if(((s[k]&mapp[i-1])==0)&&((s[j]&s[k])==0))
                        {
                            dp[i][s[j]]+=dp[i-1][s[k]];
                            dp[i][s[j]]%=100000000;
                        }
                    }
                }
            }
        }
        long long ans=0;
        for(int i=1; i<tot; i++)
        {
                ans=(ans+dp[n][s[i]])%100000000;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
