#include<stdio.h>
#include<string.h>
int a[2000010];
int num[2000010];
int main()
{
    int n,now=0;
    double sum=0;
    num[now++]=0;
    scanf("%d",&n);
    while(n--)
    {
        int t;
        scanf("%d",&t);
        if(t==1)
        {
            int b,x;
            scanf("%d%d",&b,&x);
            a[b-1]+=x;
            sum+=b*x;
        }
        else if(t==2)
        {
            int b;
            scanf("%d",&b);
            num[now++]=b;
            sum+=b;
        }
        else
        {
            sum-=a[now-1]+num[now-1];
            a[now-2]+=a[now-1];
            a[now-1]=0;
            now--;
        }
        printf("%.6lf\n",(double)sum/now);
    }
    return 0;
}