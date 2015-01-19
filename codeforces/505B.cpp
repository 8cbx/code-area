#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,a,b,c,temp,num,left,q,u,v;
    int g[105][105][30];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(g,0,sizeof(g));
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            num=c/5+1;
            left=c%5;
            temp=1<<left;
            //printf("%d %d %d\n",num,left,temp);
            g[a][b][num]|=temp;
            g[b][a][num]|=temp;
            g[a][b][0]=1;
            g[b][a][0]=1;
            //printf("%d\n",g[a][b][num]);
        }
        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                if(g[i][k][0]==1&&i!=k)
                {
                    for(int j=1; j<=n; j++)
                    {
                        if(g[k][j][0]==1&&k!=j&&i!=j)
                        {
                            //printf("%d %d %d \n",i,j,k);
                            for(int h=0;h<=21;h++)
                            {
                                g[i][j][h]|=g[i][k][h]&g[k][j][h];
                                //printf("--%d %d %d %d %d\n",i,j,k,h,g[i][j][h]);
                            }
                        }
                    }
                }
            }
        }
        scanf("%d",&q);
        for(int i=1; i<=q; i++)
        {
            scanf("%d%d",&u,&v);
            int coun=0;
            for(int h=1;h<=21;h++)
            {
               // printf("--%d\n",g[u][v][h]);
               int now=g[u][v][h];
                while(now!=0)
                {
                    if(now%2==1)
                    {
                        coun++;
                    }
                    now/=2;
                }
            }
            printf("%d\n",coun);
        }
    }
    return 0;
}
