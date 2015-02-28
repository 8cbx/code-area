#include<stdio.h>
#include<string.h>
#define min(a,b) a<b?a:b
struct node
{
    int v,next;
} edge[50010];
int head[20010],low[20010],dfn[20010];
int ins[20010],vis[20010];
int n,num,m,coun;
bool dfs(int u)
{
    low[u]=dfn[u]=++coun;
    ins[u]=true;
    int sum=0;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].v;
        if(vis[v]) return false;
        if(!dfn[v])
        {
            if(!dfs(v)) return false;
            if(low[v]>dfn[u]) return false;
            if(low[v]<dfn[u]) sum++;
            if(sum==2) return false;
            low[u]=min(low[v],low[u]);
        }
        else if(ins[v])
        {
            low[u]=min(low[u],dfn[v]);
            sum++;
            if(sum==2) return false;
        }
    }
    vis[u]=true;
    return true;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(head,-1,sizeof(head));
        memset(dfn,0,sizeof(dfn));
        memset(ins,false,sizeof(ins));
        memset(vis,false,sizeof(vis));
        num=0;
        coun=0;
        int a,b;
        scanf("%d%d",&n,&m);
        while(m--)
        {
            scanf("%d%d",&a,&b);
            edge[num].v=b;
            edge[num].next=head[a];
            head[a]=num++;
        }
        bool flag=dfs(0);
        if(flag)
        {
            for(int i=0; i<n; i++)
                if(!dfn[i])
                {
                    flag=false;
                    break;
                }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
