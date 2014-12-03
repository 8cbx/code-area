#include<stdio.h>
#include<string.h>
#define max(a,b) a>b?a:b
int main()
{
    char s[110];
    int dp[110][110];
    int i,j,k,len;
    while(scanf("%s",s+1)!=EOF)
    {
        s[0]='a';
        if(s[1]=='e')
        {
            break;
        }
        len=strlen(s);
        len--;
        memset(dp,0,sizeof(dp));
        for(i=len-1;i>=1;i--)
        {
            for(j=i+1;j<=len;j++)
            {
                dp[i][j]=dp[i+1][j];
                for(k=i+1;k<=j;k++)
                {
                    if((s[k]==')'&&s[i]=='(')||(s[k]==']'&&s[i]=='['))
                    {
                        dp[i][j]=max(dp[i][j],dp[i+1][k-1]+dp[k][j]+2);
                    }
                }
            }
        }
        printf("%d\n",dp[1][len]);
    }
    return 0;
}
