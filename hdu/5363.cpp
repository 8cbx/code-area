#include<stdio.h>
#include<string.h>
#define mod 1000000007
long long pow_mod(long long a,long long i,long long n)
{
    if(i==0)
    {
        return 1%n;
    }
    long long tmp=pow_mod(a,i>>1,n);
    tmp=tmp*tmp%n;
    if(i&1)tmp=(long long)tmp*a%n;
    return tmp;
}
int main()
{
    int t,n;
    while(scanf("%d",&t)!=EOF)
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",pow_mod(2,n-1,mod)-1);
    }
    return 0;
}
