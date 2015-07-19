#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int edgenum;
int n,m;
int flag;
int color[100010];
int colornum[2];
int head[100010];
int vis[100010];
struct data
{
    int to,next;
}edge[100010*2];
void add(int a,int b)
{
    edge[edgenum].to=b;
    edge[edgenum].next=head[a];
    head[a]=edgenum++;
}
void dfs(int u, int c)
{
    colornum[c]++;
    color[u]=c;
    vis[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(vis[v])
        {
            if(color[v]==c)
            {
                flag=0;
                return;
            }
        }
        else
            dfs(v, c^1);
    }
}
int main()
{
    int t;
    int x,y;
    int ans1,ans2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        ans1=ans2=0;
        memset(head,-1,sizeof(head));
        memset(color,-1,sizeof(color));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        if(m==0)
        {
            if(n==0||n==1)
            {
                printf("Poor wyh\n");
            }
            else
            {
                printf("%d 1\n",n-1);
            }
            continue;
        }
        edgenum=0;
        flag=1;
        for(int i=1;i<=n;i++)
        {
            //printf("%d %d\n",vis[i],i);
            if(vis[i])continue;
            memset(colornum,0,sizeof(colornum));
            dfs(i,0);
            if(colornum[0]<colornum[1]) swap(colornum[0],colornum[1]);
            ans1+=colornum[0];
            ans2+=colornum[1];
            //printf("%d %d\n",ans1,ans2);
        }
        if(flag)
        {
            printf("%d %d\n",ans1,ans2);
        }
        else
        {
            printf("Poor wyh\n");
        }
    }
    return 0;
}
