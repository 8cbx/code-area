#include<stdio.h>
#include<string.h>
int maz[3010][3010];
int vis[3010];
int n,m;
int main()
{
    int i,j,k,a,b;
    int ans;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(maz,0,sizeof(maz));
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            maz[a][b]=1;
        }
        ans=0;
        for(i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            for(j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    if(maz[i][j]==1)
                    {
                        for(k=1;k<=n;k++)
                        {
                            if(maz[j][k]==1&&k!=i)
                            {
                                if(vis[k]!=0)
                                {
                                    vis[k]++;
                                    ans+=vis[k]-1;
                                }
                                else vis[k]++;
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
