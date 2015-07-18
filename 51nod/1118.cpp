#include<stdio.h>
#include<string.h>
long long maz[1010][1010];
int main()
{
    memset(maz,0,sizeof(maz));
    for(int i=1;i<=1000;i++)
    {
        maz[i][1]=1LL;
        maz[1][i]=1LL;
    }
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=m;j++)
        {
            maz[i][j]=maz[i-1][j]+maz[i][j-1];
            maz[i][j]%=1000000007;
        }
    }
    printf("%lld\n",maz[n][m]);
    return 0;
}
