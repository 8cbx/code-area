#include<stdio.h>
#include<string.h>
int main()
{
    int maz[150][150],a[150],b[150],ma[150][150],mc[150][150];
    int n,m;
    int i,j,k;
    int flag;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(maz,0,sizeof(maz));
        memset(ma,0,sizeof(ma));
        memset(mc,0,sizeof(mc));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        flag=1;
        for(i=1;i<=m;i++)
        {
            a[i]=0;
            for(j=1;j<=n;j++)
            {
                scanf("%d",&maz[i][j]);
                if(maz[i][j]==1)
                {
                    a[i]++;
                    b[j]++;
                    flag=0;
                }
            }
        }
        /*for(i=1;i<=n;i++)
        {
            printf("%d ",b[i]);
        }
        printf("\n");
        for(i=1;i<=m;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");*/
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[i]==n&&b[j]==m)
                {
                    ma[i][j]=1;
                    flag=1;
                }
            }
        }
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(ma[i][j]==1)
                {
                    for(int ii=1;ii<=m;ii++)
                    {
                        mc[ii][j]=1;
                    }
                    for(int ii=1;ii<=n;ii++)
                    {
                        mc[i][ii]=1;
                    }
                }
            }
        }
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(maz[i][j]!=mc[i][j])
                {
                    flag=0;
                }
            }
        }
        if(flag==0)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
            for(i=1;i<=m;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if(j!=1)
                    {
                        printf(" ");
                    }
                    printf("%d",ma[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
