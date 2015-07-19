#include<stdio.h>
#include<string.h>
struct data
{
    int u,v;
}edge[10010];
struct data2
{
    int a,b,c;
}ang[100010];
int maz[1010][1010];
int main()
{
    int m,n;
    int x,y;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(maz,0,sizeof(maz));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&edge[i].u,&edge[i].v);
            maz[edge[i].v][edge[i].u]=1;
            maz[edge[i].u][edge[i].v]=1;
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(maz[j][edge[i].u]&&maz[j][edge[i].v])
                {
                    ang[ans].a=j;
                    ang[ans].b=edge[i].u;
                    ang[ans].c=edge[i].v;
                    ans++;
                }
            }
        }
        int num=0;
        for(int i=0;i<ans;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(maz[j][ang[i].a]&&maz[j][ang[i].b]&&maz[j][ang[i].c])
                {
                    num++;
                }
            }
        }
        if(num!=0)
        {
            printf("4 %d\n",num/12);
        }
        else if(ans!=0)
        {
            printf("3 %d\n",ans/3);
        }
        else if(m>=1)
        {
            printf("2 %d\n",m);
        }
        else printf("1 %d\n",n);
    }
    return 0;
}
