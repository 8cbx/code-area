#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int ta[100010];
    int vis[200010];
    int qu[100010];
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&n,&m);
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&ta[i]);
            vis[ta[i]]=1;
            if(maxx<ta[i])
            {
                maxx=ta[i];
            }
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d",&qu[i]);
            if(maxx<qu[i])
            {
                maxx=qu[i];
            }
        }
        int tmp=0;
        for(int i=maxx+10;i>0;i--)
        {
            if(vis[i]==0)
            {
                tmp=i;
                vis[i]=i;
            }
            else
            {
                vis[i]=tmp;
            }
        }
        for(int i=0;i<m;i++)
        {
            printf("%d\n",vis[qu[i]]);
        }
    }
    return 0;
}
