#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int a[10010];
    int f[10010];
    int i,j,k;
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        a[i]=0;
        n++;
        memset(f,0,sizeof(f));
        int maxx=-99999999;
        int xx,yy,x,y;
        x=1,y=0,xx=1,yy=0;
        for(i=1;i<=n;i++)
        {
            if(f[i-1]+a[i]<a[i])
            {
                f[i]=a[i];
                x=i,y=i;
            }
            else
            {
                f[i]=f[i-1]+a[i];
                y=i;
            }
            if(f[i]>maxx)
            {
                maxx=f[i];
                xx=x;
                yy=y;
            }
        }
        if(maxx==0&&xx==n&&yy==n)
        {
            xx=1;
            yy=n-1;
        }
        printf("%d %d %d\n",maxx,a[xx],a[yy]);
    }
    return 0;
}
