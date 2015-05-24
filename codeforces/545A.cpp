#include<stdio.h>
#include<string.h>
int main()
{
    int maz[110][110];
    int n;
    int flag[110];
    memset(flag,0,sizeof(flag));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&maz[i][j]);
            if(maz[i][j]==1)
            {
                flag[i]=1;
            }
            if(maz[i][j]==2)
            {
                flag[j]=1;
            }
            if(maz[i][j]==3)
            {
                flag[i]=1;
                flag[j]=1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==0)
        {
            ans++;
        }
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==0)
        {
            if(ans!=1)
                printf("%d ",i);
            else printf("%d\n",i);
            ans--;
        }
    }
    return 0;
}
