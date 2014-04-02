#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
    int x;
    string re;
};
int numcan[10];
queue<node> q;
int vis[10050],n;
char str[2];
void bfs()
{
    node popt,temp;
    str[1]='\0';
    memset(vis,0,sizeof(vis));
    int i,modi;
    while(!q.empty())
    {
        q.pop();
    }
    for(i=1; i<=9; i++)
    {
        if(numcan[i])
        {
            modi=i%n;
            temp.x=modi;
            str[0]=i+'0';
            temp.re=str;
            vis[modi]=1;
            if(modi==0)
            {
                cout<<temp.re<<endl;
                return ;
            }
            q.push(temp);
        }
    }
    while(!q.empty())
    {
        popt=q.front();
        q.pop();
        for(i=0; i<=9; i++)
        {
            if(numcan[i])
            {
                modi=(popt.x*10+i)%n;
                if(modi==0)
                {
                    cout<<popt.re<<i<<endl;
                    return;
                }
                if(!vis[modi])
                {
                    vis[modi]=1;
                    str[0]=i+'0';
                    temp.re=popt.re+str;
                    temp.x=modi;
                    q.push(temp);
                }
            }
        }
    }
    printf("-1\n");
    return;
}
int main()
{
    int m,i,j,cases=1,test;
    while(~scanf("%d%d",&n,&m))
    {
        memset(numcan,1,sizeof(numcan));
        for(i=1; i<=m; i++)
        {
            scanf("%d",&test);
            numcan[test]=0;
        }
        printf("Case %d: ",cases++);
        bfs();
    }
    return 0;
}
