#include<string.h>
#include<stdio.h>
int maz[1010][1010];
int main()
{
    int n,q;
    int a[1010];
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        int x,y;
        memset(a,0,sizeof(a));
        memset(maz,0,sizeof(maz));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[i]>a[j])
                {
                    maz[i][j]=1;
                }
            }
        }
        /*for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                printf("%d ",maz[i][j]);
            }
            printf("\n");
        }*/
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                maz[i][j]=maz[i][j]+maz[i][j-1];
            }
        }
        /*for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                printf("%d ",maz[i][j]);
            }
            printf("\n");
        }*/
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                maz[i][j]=maz[i][j]+maz[i-1][j];
            }
        }
        /*for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                printf("%d ",maz[i][j]);
            }
            printf("\n");
        }*/
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d",&x,&y);
            if(x==0)
            {
                x=1;
            }
            printf("%d\n",maz[y][y]+maz[x-1][x-1]-maz[x-1][y]-maz[y][x-1]);
        }
    }
    return 0;
}
