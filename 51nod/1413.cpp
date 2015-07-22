#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[150];
int dp[1000005];
int main()
{
    int now=(1<<7)-1;
    int wei[10];
    while(now>0)
    {
        //printf("%d\n",now);
        memset(wei,0,sizeof(wei));
        int tmp=now;
        int i=0;
        while(tmp>0)
        {
            wei[i]=tmp%2;
            tmp/=2;
            i++;
        }
        int ans=0;
        for(int j=i;j>=0;j--)
        {
            ans=ans*10+wei[j];
        }
        a[now]=ans;
        now--;
    }
    int n;
    scanf("%d",&n);
//    int coun=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=999999999;
    }
    dp[1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;a[j]<=i;j++)
        {
            dp[i]=dp[i]<(dp[i-a[j]]+1)?dp[i]:(dp[i-a[j]]+1);
        }
    }
    printf("%d\n",dp[n]);
    /*for(int i=127;i>=1;i--)
    {
        if(n>=a[i])
        {
            coun+=n/a[i];
            n%=a[i];
            printf("%d\n",a[i]);
        }
    }
    printf("%d\n",coun);*/
    return 0;
}
