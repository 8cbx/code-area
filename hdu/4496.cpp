#include<stdio.h>
#include<string.h>
int a[100010],sum[100010];
int finde(int x)
{
    if(a[x]==-1) return x;
    return a[x]=finde(a[x]);
}
int main()
{
    int i,j,k,m,n,x[100010],y[100010],xx,yy;
    while(~scanf("%d%d",&n,&m))
    {
        memset(a,-1,sizeof(a));
        sum[m]=n;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
        }
        for(i=m;i>=1;i--)
        {

            xx=finde(x[i]);
            yy=finde(y[i]);
            if(xx!=yy&&i!=1)
            {
                sum[i-1]=sum[i]-1;
                a[xx]=yy;
            }
            else if(i!=1)
            {
                sum[i-1]=sum[i];
            }
        }
        for(i=1;i<=m;i++)
        {
            printf("%d\n",sum[i]);
        }
    }
    return 0;
}
