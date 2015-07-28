#include<stdio.h>
#include<string.h>
int dir[8][2]={{-1,-1},{1,1},{-1,0},{0,-1},{0,1},{1,0},{-1,1},{1,-1}};
char s[150][150];
int n,m;
void dfs(int x,int y)
{
    int xx,yy;
    s[x][y]='*';
    for(int i=0;i<8;i++)
    {
        xx=x+dir[i][0];
        yy=y+dir[i][1];
        if(xx<0||yy<0||xx>=n||yy>=m)
        {
            continue;
        }
        if(s[xx][yy]=='@')
        {
            dfs(xx,yy);
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
        {
            break;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='@')
                {
                    dfs(i,j);
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
