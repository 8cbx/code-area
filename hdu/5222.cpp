#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <string.h>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <vector>
#define MAXN 1000005
using namespace std;
int dfn[MAXN];
int vis[MAXN];
int judge[MAXN];
int head[MAXN];
int root[MAXN];
struct Edge
{
    int to, next;
}edge[MAXN];
int n, m1, m2;
int num;
void add(int from, int to)
{
    edge[num].to = to;
    edge[num].next = head[from];
    head[from] = num++;
}
int findRoot(int x)
{
    if(x == root[x]) return x;
    else
        return root[x] = findRoot(root[x]);
}
void unite(int x, int y)
{
    x = findRoot(x);
    y = findRoot(y);
    if(x != y) root[x] = y;
}
bool flag;
void dfs(int u)
{
    dfn[u] = 1;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(judge[v])
        {
            flag = true;
            break;
        }
        if(vis[findRoot(v)])
        {
            flag = true;
            break;
        }
        if(!dfn[v])
        {
            judge[v] = 1;
            vis[findRoot(v)] = 1;
            dfs(v);
            judge[v] = 0;
            vis[findRoot(v)] = 0;
        }
        if(flag) break;
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        flag = false;
        scanf("%d%d%d", &n, &m1, &m2);
        for(int i = 1; i <= n; i++) root[i] = i;
        memset(head, -1, sizeof(head));
        memset(vis, 0, sizeof(vis));
        memset(dfn ,0 ,sizeof(dfn));
        memset(judge, 0, sizeof(judge));
        num = 0;
        for(int i = 0; i < m1; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if(findRoot(a) != findRoot(b))
            {
                unite(a, b);
            }
            else
            {
                flag = true;
            }
        }
        for(int i = 0; i < m2; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, b);
        }
        for(int i = 1; i <= n; i++)
            if(!dfn[i] && !flag)
            {
                judge[i] = 1;
                vis[findRoot(i)] = 1;
                dfs(i);
                vis[findRoot(i)] = 0;
                judge[i] = 0;
            }

        if(flag) puts("YES");
        else
            puts("NO");
    }
    return 0;
}
