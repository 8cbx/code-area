#include<stdio.h>
#include<string.h>
#define MOD 1000000007
int n;
int a[100010];
int next[100010];
int l[100010];
int r[100010];
bool vis[100010];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int ans=0,maxx=-1;
        memset(l,-1,sizeof(l));
        memset(r,-1,sizeof(r));
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            maxx = maxx>a[i]?maxx:a[i];
        }
        memset(vis,false,sizeof(vis));
        for(int i = 1; i <= n; i++)
            next[i] = 1;
        for(int i=1;i<=n;i++)
        {
            int tmp=a[i];
            l[i]=next[tmp];
            if(vis[tmp])l[i]++;
            for(int j=1;j*tmp<=maxx;j++)
            {
                int temp=j*tmp;
                vis[temp]=true;
                next[temp]=i;
            }
        }
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            next[i]=n;
        }
        for(int i=n;i>=1;i--)
        {
            int tmp=a[i];
            r[i]=next[tmp];
            if(vis[tmp])r[i]--;
            for(int j=1;j*tmp<=maxx;j++)
            {
                int temp=j*tmp;
                vis[temp]=true;
                next[temp]=i;
            }
        }
        for(int i=1;i<=n;i++)
        {
            ans=ans+(i-l[i]+1)*(r[i]-i+1)%MOD;
            ans%=MOD;
        }
        printf("%d\n",ans);
    }
    return 0;

}
