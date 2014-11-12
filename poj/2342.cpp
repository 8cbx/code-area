#include<stdio.h>
#include<string.h>
#define maxx(a,b) a>b?a:b
int fa[7000];
int dp[7000][2];
int vis[7000];
int root,n;
void treedp(int root)
{
    int i;
    vis[root]=1;
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0&&fa[i]==root)
        {
            treedp(i);
            dp[root][1]+=dp[i][0];
            dp[root][0]+=maxx(dp[i][0],dp[i][1]);
        }
    }
}
int main()
{
    int i,j,k,l,r;
    while(scanf("%d",&n)!=EOF)
    {
        memset(fa,0,sizeof(fa));
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        for(i=1; i<=n; i++)
        {
            scanf("%d",&dp[i][1]);
        }
        root=0;
        while(scanf("%d%d",&l,&r)!=EOF)
        {
            if(l==0&&r==0)
            {
                break;
            }
            fa[l]=r;
            if(root==l)
            {
                root=r;
            }
        }
        treedp(root);
        printf("%d\n",dp[root][1]>dp[root][0]?dp[root][1]:dp[root][0]);
    }
    return 0;
}
