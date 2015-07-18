#include<stdio.h>
#include<string.h>
int n,m;
int maz[510][510];
int ok(int a,int b)
{
    if(a-1>=1&&a+1<=n&&b-1>=1&&b+1<=m)
    {
        if(maz[a-1][b]==1&&(maz[a][b-1]==1||maz[a][b+1]==1))
        {
            maz[a][b]=1;
            return 1;
        }
        if(maz[a+1][b]==1&&(maz[a][b-1]==1||maz[a][b+1]==1))
        {
            maz[a][b]=1;
            return 1;
        }
    }
    else if(a==1&&b==1)
    {
        if(maz[a+1][b]==1&&maz[a][b+1]==1)
        {
            maz[a][b]=1;
            return 1;
        }
    }
    else if(a==n&&b==1)
    {
        if(maz[a-1][b]==1&&maz[a][b+1]==1)
        {
            maz[a][b]=1;
            return 1;
        }
    }
    else if(a==n&&b==m)
    {
        if(maz[a-1][b]==1&&maz[a][b-1]==1)
        {
            maz[a][b]=1;
            return 1;
        }
    }
    else if(a==1&&b==m)
    {
        if(maz[a+1][b]==1&&maz[a][b-1]==1)
        {
            maz[a][b]=1;
            return 1;
        }
    }
    else if(a==1)
    {
        if(maz[a+1][b]==1&&(maz[a][b-1]==1||maz[a][b+1]==1))
        {
            maz[a][b]=1;
            return 1;
        }
    }
    else if(a==n)
    {
        if(maz[a-1][b]==1&&(maz[a][b-1]==1||maz[a][b+1]==1))
        {
            maz[a][b]=1;
            return 1;
        }
    }
    else if(b==1)
    {
        if(maz[a][b+1]==1&&(maz[a-1][b]==1||maz[a+1][b]==1))
        {
            maz[a][b]=1;
            return 1;
        }
    }
    else if(b==m)
    {
        if(maz[a][b-1]==1&&(maz[a-1][b]==1||maz[a+1][b]==1))
        {
            maz[a][b]=1;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int g;
    int t;
    int cases=0;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        scanf("%d%d",&n,&m);
        memset(maz,0,sizeof(maz));
        scanf("%d",&g);
        int x,y;
        for(int i=1; i<=g; i++)
        {
            scanf("%d%d",&x,&y);
            maz[x][y]=1;
        }
        int flag=1;
        while(flag)
        {
            flag=0;
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=m; j++)
                {
                    if(maz[i][j]!=1)
                    {
                        if(ok(i,j)==1)
                        {
                            flag=1;
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(maz[i][j]==1)
                {
                    ans++;
                }
            }
        }
        printf("Case #%d:\n",cases);
        printf("%d\n",ans);
    }
    return 0;
}
