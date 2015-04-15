#include<string.h>
#include<stdio.h>
long long a,b,n;
long long be;
long long cacl(long long l)
{
    return be+(l-1)*b;
}
long long findd(long long l,long long t,long long m)
{
    long long left=1,right=1e6;
    long long mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if((cacl(mid)+be)*mid<=2*t*m&&be+(mid-1)*b<=t)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return right;
}
int main()
{
    long long l,t,m;
    while(scanf("%lld%lld%lld",&a,&b,&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld%lld",&l,&t,&m);
            be=a+(l-1)*b;
            long long tmpr=findd(l,t,m);
            if(tmpr<1)
            {
                printf("-1\n");
            }
            else
            {
                printf("%lld\n",tmpr+l-1);
            }
        }
    }
    return 0;
}
