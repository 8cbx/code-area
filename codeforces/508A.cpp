#include<stdio.h>
#include<string.h>
int a[1050][1050];
int n,m,k;
int check(int x,int y)
{
    if(x>=2&&y>=2)
    {
        if(a[x][y]==1&&a[x-1][y-1]==1&&a[x][y-1]==1&&a[x-1][y]==1)
        {
            return 0;
        }
    }
    if(x<=n-1&&y<=m-1)
    {
        if(a[x][y]==1&&a[x+1][y+1]==1&&a[x][y+1]==1&&a[x+1][y]==1)
        {
            return 0;
        }
    }
    if(x>=2&&y<=m-1)
    {
        if(a[x][y]==1&&a[x-1][y+1]==1&&a[x][y+1]==1&&a[x-1][y]==1)
        {
            return 0;
        }
    }
    if(x<=n-1&&y>=2)
    {
        if(a[x][y]==1&&a[x+1][y-1]==1&&a[x][y-1]==1&&a[x+1][y]==1)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{

    int x,y;

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        scanf("%d",&k);
        memset(a,0,sizeof(a));
        for(int i=1;i<=k;i++)
        {
            scanf("%d%d",&x,&y);
            a[x][y]=1;
            if(check(x,y)==0)
            {
                printf("%d\n",i);
                return 0;
            }
        }
        printf("0\n");
    }
    return 0;
}
