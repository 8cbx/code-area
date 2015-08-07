#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int fa[1010];
struct data
{
    int s,e,w;
}edge[50010];
int cmp(data a,data b)
{
    return a.w<b.w;
}
int findfa(int a)
{
    if(fa[a]==a)
    {
        return a;
    }
    return fa[a]=findfa(fa[a]);
}
void un(int a,int b)
{
    int aa=findfa(a);
    int bb=findfa(b);
    if(aa!=bb)
    {
        fa[aa]=bb;
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&edge[i].s,&edge[i].e,&edge[i].w);
    }
    sort(edge+1,edge+1+m,cmp);
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        if(findfa(edge[i].s)!=findfa(edge[i].e))
        {
            ans+=edge[i].w;
            un(edge[i].s,edge[i].e);
        }
    }
    printf("%d\n",ans);
    return 0;
}
