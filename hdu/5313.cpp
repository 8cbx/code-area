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
struct data2
{
    int a,b;
}a[100010];
int minans[100010];
int maxans[100010];
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
int cmp(data2 a,data2 b)
{
    if(a.a==b.a)
    {
        return a.b>b.b;
    }
    return a.a>b.a;
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
        memset(a,0,sizeof(a));
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
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
            a[i].a=colornum[0];
            a[i].b=colornum[1];
            //printf("%d %d\n",ans1,ans2);
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            if(ans1>ans2)swap(ans1,ans2);
            ans1+=a[i].a;
            ans2+=a[i].b;
        }
        printf("%d\n",ans1*ans2-m);
    }
    return 0;
}
