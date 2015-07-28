#include<stdio.h>
#include<string.h>
char s[100][100];
int w,h;
int vis[100][100];
int ans;
int dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
void dfs(int x,int y)
{
    int xx,yy;
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        xx=x+dir[i][0];
        yy=y+dir[i][1];
        if(xx<0||yy<0||xx>=h||yy>=w)
        {
            continue;
        }
        if(s[xx][yy]=='.'&&vis[xx][yy]==0)
        {
            ans++;
            dfs(xx,yy);
        }
    }
}
int main()
{
    while(scanf("%d%d",&w,&h)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        ans=0;
        if(w==0&&h==0)
        {
            break;
        }
        for(int i=0;i<h;i++)
        {
            scanf("%s",s[i]);
        }
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(s[i][j]=='@')
                {
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
