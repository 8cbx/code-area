#include<string.h>
#include<stdio.h>
long long gcd(long long a,long long b)
{
    return (b>0)?gcd(b,a%b):a;
}
int main()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld\n",gcd(a,b));
    return 0;
}
