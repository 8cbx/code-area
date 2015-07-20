#include<stdio.h>
#include<string.h>
#define MAXN 55*55
int nx,ny;
int g[MAXN][MAXN];
int cx[MAXN],cy[MAXN];
int mk[MAXN];
int queue[MAXN];
int pred[MAXN];
int MaxMatch()
{
    int y;
    int cur,tail;
    int res=0;
    memset(cx,0xffff,sizeof(cx));
    memset(cy,0xffff,sizeof(cy));
    for(int i=0;i<ny;i++)
    {
        if(cx[i]!=-1)
        {
            continue;
        }
        for(int j=0;j<ny;j++)
        {
            pred[j]=-2;
        }
        cur=tail=0;
        for(int j=0;j<ny;j++)
        {
            if(g[i][j])
            {
                pred[j]=-1;
                queue[tail++]=j;
            }
        }
        while(cur<tail)
        {
            y=queue[cur];
            if(cy[y]==-1)
            {
                break;
            }
            cur++;
            for(int j=0;j<ny;j++)
            {
                if(pred[j]==-2&&g[cy[y]][j])
                {
                    pred[j]=y;
                    queue[tail++]=j;
                }
            }
        }
        if(cur==tail)
        {
            continue;
        }
        while(pred[y]>-1)
        {
            cx[cy[pred[y]]]=y;
            cy[y]=cy[pred[y]];
            y=pred[y];
        }
        cy[y]=i;
        cx[i]=y;
        res++;
    }
    return res;
}
int main()
{
    int t;
    int n,m;
    char s[55][55];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(g,0,sizeof(g));
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
        }
        int coun1=0;
        int coun2=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='.')
                    coun1++;
                else if(s[i][j]=='o')
                    coun2++;
            }
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<m-1;j++)
            {
                if(s[i][j]=='.')
                {
                    if(s[i+1][j]=='o')
                    {
                        g[i*m+j][i*m+m+j]=1;
                        g[i*m+m+j][i*m+j]=1;
                    }
                    if(s[i][j+1]=='o')
                    {
                        g[i*m+j][i*m+j+1]=1;
                        g[i*m+j+1][i*m+j]=1;
                    }
                }
                if(s[i][j]=='o')
                {
                    if(s[i+1][j]=='.')
                    {
                        g[i*m+j][i*m+m+j]=1;
                        g[i*m+m+j][i*m+j]=1;
                    }
                    if(s[i][j+1]=='.')
                    {
                        g[i*m+j][i*m+1+j]=1;
                        g[i*m+1+j][i*m+j]=1;
                    }
                }
            }
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i][m-1]=='.')
            {
                if(s[i+1][m-1]=='o')
                {
                    g[i*m+m-1][i*m+m+m-1]=1;
                    g[i*m+m+m-1][i*m+m-1]=1;
                }
            }
            if(s[i][m-1]=='o')
            {
                if(s[i+1][m-1]=='.')
                {
                    g[i*m+m-1][i*m+m+m-1]=1;
                    g[i*m+m+m-1][i*m+m-1]=1;
                }
            }
        }
        for(int j=0;j<m-1;j++)
        {
            if(s[n-1][j]=='.')
            {
                if(s[n-1][j+1]=='o')
                {
                    g[(n-1)*m+j][(n-1)*m+j+1]=1;
                    g[(n-1)*m+j+1][(n-1)*m+j]=1;
                }
            }
            if(s[n-1][j]=='o')
            {
                if(s[n-1][j+1]=='.')
                {
                    g[(n-1)*m+j][(n-1)*m+j+1]=1;
                    g[(n-1)*m+j+1][(n-1)*m+j]=1;
                }
            }
        }
        /*for(int i=0;i<=n*m;i++)
        {
            for(int j=0;j<=n*m;j++)
            {
                if(g[i][j]==1)
                {
                    printf("%d %d-%d %d\n",i/m,i%m,j/m,j%m);
                }
            }
        }*/
        nx=n*m;
        ny=n*m;
        int ans=MaxMatch()/2;
        //printf("%d\n",ans);
        printf("%d\n",coun1+coun2-ans);
    }
    return 0;
}
