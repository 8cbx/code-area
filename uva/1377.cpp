#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
int d[55];
int vis[(1<<22)+10];
int idx[1010010];
int n,now;
struct node
{
    int coun;
    int hashs;
    int used[10];
};
bool endle(int a)
{
    if(a==(1<<now)-1)return true;
    return false;
}
int sameornot(int *a,int b,int c)
{
    for(int i=0; i<b; i++)
    {
        if(a[i]==c)
        {
            return 1;
        }
    }
    return 0;
}
bool notfound(int a,int coun)
{
    for(int i=0; i<coun; i++)
    {
        if(d[i]==a)
        {
            return false;
        }
    }
    return true;
}
void did(node &cur,int need)
{
    for(int i=0; i<cur.coun; i++)
    {
        int t=abs(need-cur.used[i]);
        if(idx[t]!=-1)cur.hashs|=(1<<idx[t]);
    }
    cur.used[cur.coun++]=need;
    sort(cur.used,cur.used+cur.coun);
    return;
}
node BFS()
{
    memset(vis,0,sizeof(vis));
    queue<node> Q;
    node st;
    st.coun=1;
    st.hashs=1;
    st.used[0]=0;
    vis[st.hashs]=1;
    Q.push(st);
    while(!Q.empty())
    {
        node cur=Q.front();
        Q.pop();
        if(endle(cur.hashs))return cur;
        for(int i=0; i<cur.coun; i++)
        {
            for(int j=0; j<now; j++)
            {
                if(cur.hashs&(1<<j))continue;
                int x=cur.used[i]+d[j];
                if(sameornot(cur.used,cur.coun,x)||x>d[now-1])continue;
                node temp=cur;
                did(temp,x);
                if(!vis[temp.hashs])
                {
                    vis[temp.hashs]=1;
                    if(endle(temp.hashs))return temp;
                    Q.push(temp);
                }
            }
            for(int j=0; j<now; j++)
            {
                if(cur.hashs&(1<<j))continue;
                int x=cur.used[i]-d[j];
                if(sameornot(cur.used,cur.coun,x)||x>d[now-1]||x<0)continue;
                node temp=cur;
                did(temp,x);
                if(!vis[temp.hashs])
                {
                    vis[temp.hashs]=1;
                    if(endle(temp.hashs))return temp;
                    Q.push(temp);
                }
            }
        }
    }
    return st;
}
int main()
{
    int t,temp;
    t=0;
    while(scanf("%d",&n)!=EOF)
    {
        t++;
        if(n==0)
        {
            return 0;
        }
        printf("Case %d:\n",t);
        d[0]=0;
        now=1;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&temp);
            //printf("%d\n",notfound(temp,now));
            if(notfound(temp,now))
            {
                d[now++]=temp;
            }
        }
        sort(d,d+now);
        memset(idx,-1,sizeof(idx));
        for(int i=0; i<now; i++)
        {
            idx[d[i]]=i;
        }
        node ans=BFS();
        printf("%d\n",ans.coun);
        for(int i = 0; i<ans.coun; ++i)
        {
            if(i) putchar(' ');
            printf("%d",ans.used[i]);
        }
        puts("");
    }
    return 0;
}
