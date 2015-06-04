#include<stdio.h>
#include<string.h>
int main()
{
    int maz[550][550];
    int n,m,k;
    int x,y;
    int ans=0;
    int anss[550];
    int res;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        ans=0;
        res=0;
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&maz[i][j]);
            if(maz[i][j]==1)
            {
                res++;
            }
            else
            {
                res=0;
            }
            ans=res>ans?res:ans;
        }
        anss[i]=ans;
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d",&x,&y);
        if(maz[x][y]==1)
        {
            maz[x][y]=0;
        }
        else
        {
            maz[x][y]=1;
        }
        ans=0;
        res=0;
        for(int j=1;j<=m;j++)
        {
            if(maz[x][j]==1)
            {
                res++;
            }
            else
            {
                res=0;
            }
            ans=res>ans?res:ans;
        }
        anss[x]=ans;
        int max=0;
        for(int j=1;j<=n;j++)
        {
            if(max<anss[j])
            {
                max=anss[j];
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
