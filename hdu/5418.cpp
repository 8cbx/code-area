#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
struct data
{
    int now,sta;
};
queue<data>q;
int dp[65540][20];
int vis[65540][20];
int maz[20][20];
int n;
void floyd()
{
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        for(k=1;k<=n;k++)
        {
            for(j=1;j<=n;j++)
            {
                if(k==i||k==j)continue;
                if(maz[i][k]+maz[k][j]<maz[i][j])
                {
                    maz[i][j]=maz[i][k]+maz[k][j];
                }
            }
        }
    }
}
int main()
{
    int t;
    int u,v,w;
    int m;
    scanf("%d",&t);
    while(t--)
    {
        while(!q.empty())
        {
            q.pop();
        }
        scanf("%d",&n);
        scanf("%d",&m);
        memset(maz,-1,sizeof(maz));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                maz[i][j]=99999999;
            }
        }
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            if(maz[u][v]>w)
            {
                maz[u][v]=w;
            }
            if(maz[v][u]>w)
            {
                maz[v][u]=w;
            }
        }
        memset(vis,0,sizeof(vis));
        if(n==1)
        {
            printf("0\n");
continue;
        }
        memset(dp,0,sizeof(dp));
        /*for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                printf("%d ",maz[i][j]);
            }
            printf("\n");
        }*/
        floyd();
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maz[j][i]=maz[i][j];
            }
        }
        /*for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                printf("%d ",maz[i][j]);
            }
            printf("\n");
        }*/
        int target=(1<<n)-1;
        dp[1][1]=0;
        int now=1;
        data cur;
        cur.now=now;
        cur.sta=1;
        vis[cur.now][cur.sta]=1;
        q.push(cur);
        while(!q.empty())
        {
            cur=q.front();
            //printf("%d %d %d\n",cur.now,cur.sta,dp[cur.now][cur.sta]);
            q.pop();
            now=cur.now;
            for(int i=1; i<=n; i++)
            {
                if(((now>>(i-1))&1)==0)
                {
                    //printf("togo? : %d %d\n",(now>>(i-1))&1,i);
                    if(cur.sta!=i)
                    {
                        data tmp;
                        tmp.sta=i;
                        tmp.now=now|(1<<(i-1));
                        //printf("from %d %d %d\n",cur.now,cur.sta,dp[cur.now][cur.sta]);
                        //printf("to   %d %d %d\n",tmp.now,tmp.sta,dp[tmp.now][tmp.sta]);
                        if(vis[tmp.now][tmp.sta]==0)
                        {
                            q.push(tmp);
                            vis[tmp.now][tmp.sta]=1;
                        }
                        if(dp[now|1<<(i-1)][i]==0)
                        {
                            dp[now|1<<(i-1)][i]=dp[now][cur.sta]+maz[cur.sta][i];
                        }
                        else dp[now|1<<(i-1)][i]=min(dp[now|1<<(i-1)][i],dp[now][cur.sta]+maz[cur.sta][i]);
                        //printf("to   %d %d %d\n",tmp.now,tmp.sta,dp[tmp.now][tmp.sta]);
                    }
                }
            }
        }
        int ans=9999999;
        for(int i=2; i<=n; i++)
        {
            //printf("%d\n",dp[target][i]);
            if(maz[i][1]!=-1&&dp[target][i]!=0&&ans>dp[target][i]+maz[i][1])
            {
                ans=dp[target][i]+maz[1][i];
            }
        }
        if(ans==9999999)
        {
            ans=0;
        }
        printf("%d\n",ans);
    }
    return 0;
}
