#include<stdio.h>
#include<string.h>
#define min(a,b,c) (a<b?(a<c?a:c):(b<c?b:c))
int dp[1010][1010];
int main()
{
    char s[1010];
    char ss[1010];
    int len1,len2;
    scanf("%s",s);
    scanf("%s",ss);
    len1=strlen(s);
    len2=strlen(ss);
    for(int i=0;i<len1+1;i++)
    {
        dp[i][0]=i;
    }
    for(int i=0;i<len2+1;i++)
    {
        dp[0][i]=i;
    }
    for(int i=1; i<len1+1; i++)
    {
        for(int j=1; j<len2+1; j++)
        {
            if(s[i-1]==ss[j-1])
            {
                dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]);
            }
            else
            {
                dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1);
            }

        }
    }
    /*for(int i=0; i<len1+1; i++)
    {
        for(int j=0; j<len2+1; j++)
        {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }*/
    printf("%d\n",dp[len1][len2]);
    return 0;
}
