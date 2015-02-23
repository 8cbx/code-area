#include<stdio.h>
#include<string.h>
struct point
{
    int x,y;
};
int main()
{
    int maz[250][250];
    int used[250][250];
    point ans[250*250],b[250*250];
    int now;
    int cur;
    int flag;
    int fin,n,m;
    int dx[5]= {0,1,-1,0,0};
    int dy[5]= {0,0,0,1,-1};
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(maz,0x7f,sizeof(maz));
        int INF=maz[2][2];
        memset(b,0,sizeof(b));
        memset(used,0,sizeof(used));
        memset(ans,0,sizeof(ans));
        fin=0;
        cur=1;
        flag=0;
        now=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&maz[i][j]);
                if(maz[i][j]==1)
                {
                    now++;
                    b[now].x=i;
                    b[now].y=j;
                }
            }
        }
        while(cur<=now)
        {
            fin++;
            ans[fin].x=b[cur].x;
            ans[fin].y=b[cur].y;
            maz[b[cur].x][b[cur].y]--;
            used[b[cur].x][b[cur].y]=1;
            for(int i=1; i<=4; i++)
            {
                if(maz[b[cur].x+dx[i]][b[cur].y+dy[i]]==INF)
                {
                    continue;
                }
                if(used[b[cur].x+dx[i]][b[cur].y+dy[i]]==0)
                {
                    maz[b[cur].x+dx[i]][b[cur].y+dy[i]]--;
                    if(maz[b[cur].x+dx[i]][b[cur].y+dy[i]]==1)
                    {
                        now++;
                        b[now].x=b[cur].x+dx[i];
                        b[now].y=b[cur].y+dy[i];
                    }
                }
            }
            cur++;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(used[i][j]!=1||maz[i][j]!=0)
                {
                    flag=1;
                }
            }
        }
        if(flag==1)
        {
            printf("No solution\n");
        }
        else
        {
            for(int i=fin;i>=1;i--)
            {
                printf("%d %d\n",ans[i].x,ans[i].y);
            }
        }
    }
    return 0;
}
