#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
vector<int>edge[100010];
int value[100010];
void ask(int a)
{
    long long ans=0;
    for(int i=0;i<(int)edge[a].size();i++)
    {
        ans+=value[edge[a][i]];
    }
    printf("%lld\n",ans);
}
int main()
{
    int t;
    int n,m,q;
    scanf("%d",&t);
    while(t--)
    {
        memset(value,0,sizeof(value));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            edge[i].clear();
        }
        int u,v;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        scanf("%d",&q);
        int cmd;
        for(int i=1;i<=q;i++)
        {
            scanf("%d",&cmd);
            {
                if(cmd==0)
                {
                    scanf("%d%d",&u,&v);
                    value[u]+=v;
                }
                else
                {
                    scanf("%d",&u);
                    ask(u);
                }
            }
        }
    }
    return 0;
}
