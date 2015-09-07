#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int vis[1010];
int maz[1010][1010];
int go[1010];
int num[1010];
int n;
queue<int>q;
int bfs(int now)
{
    while(!q.empty())
    {
        q.pop();
    }
    go[now]=1;
    vis[now]=1;
    num[1]=1;
    q.push(now);
    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
        go[tmp]=1;

        for(int i=1;i<=n;i++)
        {
            if(go[i]==0&&maz[i][tmp]==1)
            {
                //printf("push %d\n",i);
                num[vis[tmp]+1]++;
                vis[i]=vis[tmp]+1;
                go[i]=1;
                q.push(i);
            }
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        printf("%d ",num[i]);
    }
    printf("\n");*/
    int coun=1;
    while(num[coun]!=0)
    {
        if(num[coun]>1&&num[coun+1]!=0)
        {
            return 0;
        }
        coun++;
    }
    return 1;
}
int main()
{
    int u,v;
    while(scanf("%d",&n)!=EOF)
    {
        memset(go,0,sizeof(go));
        memset(vis,0,sizeof(vis));
        memset(maz,0,sizeof(maz));
        memset(num,0,sizeof(num));
        for(int i=1; i<n; i++)
        {
            scanf("%d%d",&u,&v);
            maz[u][v]=1;
            maz[v][u]=1;
        }
        if(bfs(1)==1)
        {
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }
    return 0;
}
