#include<stdio.h>
#include<string.h>
#define MAXN 10010
#define max(a,b) a>b?a:b
struct edge
{
    int u,v,w,next;
}E[MAXN<<1];
int head[MAXN];
int top;
long long dp[MAXN<<1];
void add_edge(int u,int v,int w)
{
    E[top].u=u;
    E[top].v=v;
    E[top].w=w;
    E[top].next=head[u];
    head[u]=top++;
}
long long dfs(int u,int p)
{
    long long ans=0;
    for(int i=head[u];~i;i=E[i].next)
    {
        int v=E[i].v;
        if(v==p)
        {
            continue;
        }
        if(dp[i]==0)
        {
            dp[i]=dfs(v,u)+E[i].w;
        }
        if(ans<dp[i])
        {
            ans=dp[i];
        }
    }
    return ans;
}
int main()
{
    int i,j,n;
    int v,w;
    while(scanf("%d",&n)!=EOF)
    {
        top=0;
        memset(head,-1,sizeof(head));
        memset(dp,0,sizeof(dp));
        for(i=2;i<=n;i++)
        {
            scanf("%d%d",&v,&w);
            add_edge(i,v,w);
            add_edge(v,i,w);
        }
        for(i=1;i<=n;i++)
        {
            printf("%I64d\n",dfs(i,i));
        }
    }
    return 0;
}
