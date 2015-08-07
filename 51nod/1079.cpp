#include<stdio.h>
#include<string.h>
long long exte_gcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        long long r=exte_gcd(b,a%b,y,x);
        y-=x*(a/b);
        return r;
    }
}
long long CRT(long long a[],long long m[],long long n)
{
    long long M=1;
    for(long long i=0;i<n;i++)
    {
        M*=m[i];
    }
    long long ret=0;
    for(long long i=0;i<n;i++)
    {
        long long x,y;
        long long tm=M/m[i];
        exte_gcd(tm,m[i],x,y);
        ret=(ret+tm*x*a[i])%M;
    }
    return (ret+M)%M;
}
int main()
{
    long long n;
    long long a[15],m[15];
    scanf("%lld",&n);
    for(long long i=0;i<n;i++)
    {
        scanf("%lld%lld",&m[i],&a[i]);
    }
    printf("%lld\n",CRT(a,m,n));
    return 0;
}
