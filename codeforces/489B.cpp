#include<stdio.h>
#include<math.h>
#include<string.h>
const int MAXN=150;
int uN,vN;
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)
{
    int v;
    for(v=0; v<vN; v++)
        if(g[u][v]&&!used[v])
        {
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v]))
            {
                linker[v]=u;
                return true;
            }
        }
    return false;
}
int hungary()
{
    int res=0;
    int u;
    memset(linker,-1,sizeof(linker));
    for(u=0; u<uN; u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}
int main()
{
    int a[150],b[150],i,j;
    while(scanf("%d",&uN)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(g,0,sizeof(g));
        for(i=0; i<uN; i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&vN);
        for(i=0; i<vN; i++)
        {
            scanf("%d",&b[i]);
        }
        for (i = 0; i < uN; i++)
        {
            for (j = 0; j < vN; j++)
                if(fabs(a[i]-b[j])<=1)
                    g[i][j] = 1;
        }
        /*for (i = 1; i <= uN; i++)
        {
           for (j = 1; j <= vN; j++)
                   g[i][j] = 1;
        }*/
        //hungary();
        printf("%d\n",hungary());
    }
    return 0;
}
