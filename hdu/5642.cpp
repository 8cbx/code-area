#include<stdio.h>
#include<string.h>
long long dp[2500];
int main()
{
    int t;
    scanf("%d",&t);
    dp[1]=1;
    dp[2]=26;
    dp[3]=676;
    for(int i=4; i<=2010; i++)
    {
        dp[i]=dp[i-1]*25+dp[i-2]*25+dp[i-3]*25;
        dp[i]%=1000000007;
    }
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%I64d\n",dp[n]*26%1000000007);
    }
    return 0;
}
