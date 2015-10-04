#include<stdio.h>
#include<string.h>
int data[100010];
int a[100010];
int vis[100010];
int dfs(int now)
{
    vis[now]=1;
    int ans=1;
    while(vis[data[now]]==0)
    {
        vis[data[now]]=1;
        now=data[now];
        ans++;
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(data,0,sizeof(data));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&data[a[i]]);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                int tmp;
                tmp=dfs(i);
                if(tmp==1)
                {
                    ans+=1;
                }
                else if(tmp!=0)
                {
                    ans+=tmp-1;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
