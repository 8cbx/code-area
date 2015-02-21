#include<stdio.h>
#include<string.h>
int maz[20][20];
int stat[20][20];
int ans[20][20];
int n,m;

int check(int s)
{
    for(int i=0; i<m; i++)
    {
        if(s&(1<<i))
        {
            ans[0][i]=1;
            stat[0][i]^=1;
            if(n>1)
            {
                stat[1][i]^=1;
            }
            if(i<m-1)
            {
                stat[0][i+1]^=1;
            }
            if(i>0)
            {
                stat[0][i-1]^=1;
            }
        }
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(stat[i-1][j])
            {
                ans[i][j]=1;
                stat[i][j]^=1;
                stat[i-1][j]^=1;
                if(n-1>=i+1)
                {
                    stat[i+1][j]^=1;
                }
                if(j<m-1)
                {
                    stat[i][j+1]^=1;
                }
                if(j>0)
                {
                    stat[i][j-1]^=1;
                }
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        if(stat[n-1][i])
        {
            return 0;
        }
    }
    return 1;
}

void printans()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            printf("%d ",ans[i][j]);
        }
        printf("%d\n",ans[i][m-1]);
    }
}

int main()
{
    int flag;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        flag=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%d",&maz[i][j]);
            }
        }
        for(int i=0; i<(1<<m); i++)
        {
            memcpy(stat,maz,sizeof(maz));
            memset(ans,0,sizeof(ans));
            if(check(i))
            {
                printans();
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}
