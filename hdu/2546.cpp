#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}
int main()
{
    int n,i,j,m;
    int pr[1050],dp[1100];
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&pr[i]);
        }
        qsort(pr+1,n,sizeof(pr[0]),cmp);
        scanf("%d",&m);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            for(j=m;j>=0;j--)
            {
                if(j<5)
                {
                    dp[j]=0;
                }
                else if(j-pr[i]<5)
                {
                    dp[j]=dp[j]>pr[i]?dp[j]:pr[i];
                }
                else if(dp[j]<dp[j-pr[i]]+pr[i])
                {
                    dp[j]=dp[j-pr[i]]+pr[i];
                }
            }
        }
        //if(m>=5)
        printf("%d\n",m-dp[m]);
        //else printf("%d\n",m);
    }
    return 0;
}
