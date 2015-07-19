#include<string.h>
#include<stdio.h>
#define max(a,b) a>b?a:b
#define MOD 1000000007
int dp[1010][1010];
int f[1010][1010];
int main()
{
    char s[1010];
    char ss[1010];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        memset(f,0,sizeof(f));
        scanf("%s",s);
        scanf("%s",ss);
        int len1=strlen(s);
        int len2=strlen(ss);
        for(int i=0; i<=len1; i++)
        {
            f[i][0]=1;
        }
        for(int i=0; i<=len2; i++)
        {
            f[0][i]=1;
        }
        for(int i=0; i<len1; i++)
        {
            for(int j=0; j<len2; j++)
            {
                if(s[i]==ss[j])
                {
                    dp[i+1][j+1]=dp[i][j]+1;
                    f[i+1][j+1]=f[i][j];
                    if(dp[i][j+1]==dp[i+1][j+1])
                    {
                        f[i+1][j+1]=(f[i+1][j+1]+f[i][j+1])%MOD;
                    }
                }
                else
                {
                    dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
                    if(dp[i+1][j+1]==0)
                    {
                        f[i+1][j+1]=1;
                    }
                    else
                    {
                        if(dp[i][j+1]!=dp[i+1][j])
                        {
                            if(dp[i+1][j+1]==dp[i][j+1])
                            {
                                f[i+1][j+1]=f[i][j+1];
                            }
                            else if(dp[i+1][j+1]==dp[i+1][j])
                            {
                                f[i+1][j+1]=f[i+1][j];
                            }
                        }
                        else
                        {
                            if(dp[i][j]==dp[i+1][j+1])
                            {
                                f[i+1][j+1]=((f[i][j+1]+f[i+1][j]-f[i][j])%MOD+MOD)%MOD;
                            }
                            else
                            {
                                f[i+1][j+1]=((f[i][j+1]+f[i+1][j])%MOD+MOD)%MOD;
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",f[len1][len2]);
    }
    return 0;
}
