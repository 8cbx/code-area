//论坛上的代码，我自己的始终超时过不去，不知为何……
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[35];
int f[3000500];
int main()
{
    int n,top,m;
    double q;
    while(scanf("%lf%d",&q,&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        char type;
        double price;
        int i,j,x,a,b,c,tag,top;
        int mon[35];
        top=(int)(q*100);
        memset(f,0,sizeof(f));
        memset(mon,0,sizeof(mon));
        for(i=1;i<=n;i++)
        {
            a=b=c=tag=0;
            scanf("%d",&m);
            for(j=1;j<=m;j++)
            {
                scanf("%*c%c:%lf",&type,&price);
                x=(int)(price*100);
                if(type=='A')
                {
                    a+=x;
                }
                else if(type=='B')
                {
                    b+=x;
                }
                else if(type=='C')
                {
                    c+=x;
                }
                else tag=1;
            }
            if(tag!=1&&a+b+c<=100000&&a<=60000&&b<=60000&&c<=60000)
            {
                mon[i]=a+b+c;
            }
            else
            {
                mon[i]=top+1;
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=top;j>=mon[i];j--)
            {
                if(f[j-mon[i]]+mon[i]>f[j])
                {
                    f[j]=f[j-mon[i]]+mon[i];
                }
            }
        }
        printf("%.2lf\n",f[top]/100.0);
    }
    return 0;
}
