#include<stdio.h>
#include<string.h>
int main()
{
    char maz[110][110];
    int coun;
    int i,j,n,t,m,cas;
    while(scanf("%d",&t)!=EOF)
    {
        cas=0;
        while(t--)
        {
            cas++;
            coun=0;

            scanf("%d%d",&n,&m);
            for(i=1;i<=n;i++)
            {
                scanf("%s",maz[i]);
            }
            for(i=1;i<=n;i++)
            {
                for(j=0;j<m;j++)
                {
                    if(maz[i][j]=='O')
                    {
                        coun++;
                    }
                }
            }
            printf("Case %d: ",cas);
            if(coun%2==0)
            {
                printf("Fat brother\n");
            }
            else printf("Maze\n");
        }
    }
    return 0;
}
