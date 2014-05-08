//加排序，以p-q排；
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct vic
{
    int p,v,q;
} v[510];
bool cmp(const vic &a,const vic &b)
{
    return a.q-a.p<b.q-b.p;
}
int main()
{
    int n,m,i,j,temp;
    int dp[5010];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d",&v[i].p,&v[i].q,&v[i].v);
        }
        sort(v+1,v+1+n,cmp);
        /*for(i=1;i<=n;i++)
        {
            printf("%d %d %d\n",q[i],p[i],q[i]-p[i]);
        }*/
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            for(j=m;j>=v[i].q;j--)
            {
                if(dp[j]<dp[j-v[i].p]+v[i].v)
                {
                    dp[j]=dp[j-v[i].p]+v[i].v;
                }
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
