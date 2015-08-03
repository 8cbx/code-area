#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct point
{
    int x,y,t;
};
char s1[5],s2[5];
queue<point> q;
int vis[10][10];
int dir[8][2]={{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
int inrange(point tmp)
{
    if(tmp.x<=8&&tmp.x>=1&&tmp.y<=8&&tmp.y>=1)
    {
        return 1;
    }
    return 0;
}
void bfs(point a,point b)
{
    while(!q.empty())
    {
        q.pop();
    }
    q.push(a);
    while(!q.empty())
    {
        point now=q.front();
        q.pop();
        if(now.x==b.x&&now.y==b.y)
        {
            printf("To get from %s to %s takes %d knight moves.\n",s1,s2,now.t);
            break;
        }
        point tmp;
        for(int i=0;i<8;i++)
        {
            tmp.x=now.x+dir[i][0];
            tmp.y=now.y+dir[i][1];
            tmp.t=now.t+1;
            if(inrange(tmp)&&vis[tmp.x][tmp.y]!=1)
            {
                q.push(tmp);
                vis[tmp.x][tmp.y]=1;
            }
        }
    }
}
int main()
{
    point a,b;
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        a.x=s1[0]-'a'+1;
        b.x=s2[0]-'a'+1;
        a.t=0;
        a.y=s1[1]-'0';
        b.y=s2[1]-'0';
        memset(vis,0,sizeof(vis));
        vis[a.x][a.y]=1;
        bfs(a,b);
    }
}
