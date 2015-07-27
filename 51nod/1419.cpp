#include<stdio.h>
#include<string.h>
long long lcm(long long m,long long n)
{
    long long p;
    long long r,tmp;
    if(n<m)
    {
        tmp=n;
        n=m;
        m=tmp;
    }
    p=n*m;
    while(m!=0)
    {
        r=n%m;
        n=m;
        m=r;
    }
    return p/n;
}
int main()
{
    long long n;
    scanf("%lld",&n);
    if(n<=2)
    {
        printf("%lld\n",n);
    }
    else if(n%2==1)
    {
        printf("%lld\n",n*(n-1)*(n-2));
    }
    else
    {
        long long max=0;
        for(long long i=n;i>=n-5LL;i--)
        {
            for(long long j=n;j>=n-5LL;j--)
            {
                for(long long k=n;k>=n-5LL;k--)
                {
                    long long ans=lcm(i,lcm(j,k));
                    if(ans>max)
                    {
                        max=ans;
                    }
                }
            }
        }
        printf("%lld\n",max);
    }
    return 0;
}
