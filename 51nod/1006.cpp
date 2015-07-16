#include<string.h>
#include<stdio.h>
#define max(a,b) a>b?a:b
int dp[1010][1010];
int main()
{
    char s[1010];
    char ss[1010];
    int skip[1010];
    memset(dp,0,sizeof(dp));
    memset(skip,0,sizeof(skip));
    scanf("%s",s);
    scanf("%s",ss);
    int len1=strlen(s);
    int len2=strlen(ss);
    for(int i=0;i<len1;i++)
    {
        for(int j=0;j<len2;j++)
        {
            if(s[i]==ss[j])
            {
                dp[i+1][j+1]=dp[i][j]+1;
            }
            else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
        }
    }
    for(int i=len1-1,j=len2-1;i>=0&&j>=0;)
    {
        if(s[i]==ss[j])
        {
            skip[i]=1;
            i--;
            j--;
        }
        else
        {
            if(dp[i+1][j]>dp[i][j+1])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    for(int i=0;i<len1;i++)
    {
        if(skip[i]==1)
        {
            printf("%c",s[i]);
        }
    }
    printf("\n");
    return 0;
}
