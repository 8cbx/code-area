#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    //freopen("1","r",stdin);
    int i,j,k;
    int a[100010];
    int f[100010];
    int case1,n,m;
    int x,y,xx,yy,maxx;
    scanf("%d",&m);
    case1=0;
    while(m--)
    {
        maxx=-99999999;
        x=1;
        xx=0;
        yy=0;
        y=0;
        case1++;
        scanf("%d",&n);
        memset(f,0,sizeof(f));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++)
        {
            if (a[i]<=f[i-1]+a[i])
            {
                f[i]=f[i-1]+a[i];
                y++;
                //printf("%d-y %d\n",f[i],y);
            }
            else
            {
                f[i]=a[i];
                x=i;
                y=i;
                //printf("x %d-y %d\n",x,y);
            }
            if(f[i]>maxx)
            {
                maxx=f[i];
                xx=x;
                yy=y;
                //printf("%d--%d--%d--%d\n",maxx,i,xx,yy);
            }

        }
        if(xx==0||yy==0)
        {
            xx=1;
            yy=1;
        }
        printf("Case %d:\n",case1);
        printf("%d %d %d\n",maxx,xx,yy);
        if(m!=0)printf("\n");
    }
    return 0;
}
