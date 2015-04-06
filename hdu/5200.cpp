#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct tree
{
    int h,id;
    bool operator < (const struct tree &tmp)
    {
        return h>tmp.h;
    }
} p[50010];
struct qu
{
    int h,id;
    bool operator < (const struct qu &tmp)
    {
        return h<tmp.h;
    }
} q[50010];
int main()
{
    int n,m;
    int vis[50010];
    int ans[50010];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&p[i].h);
            p[i].id=i;
        }
        sort(p+1,p+1+n);
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&q[i].h);
            q[i].id=i;
        }
        sort(q+1,q+1+m);
        int tot=0;
        for(int i=1,j=m; j>0; j--)
        {
            for(; i<=n; i++)
            {
                if(p[i].h<=q[j].h)
                {
                    break;
                }
                vis[p[i].id]=1;
                if(vis[p[i].id+1]==0&&vis[p[i].id-1]==0)
                {
                    tot++;
                }
                else
                {
                    if(vis[p[i].id+1]==1&&vis[p[i].id-1]==1)
                    {
                        tot--;
                    }
                }
            }
            ans[q[j].id]=tot;
        }
        for(int i=1; i<=m; i++)
        {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
