#include<stdio.h>
#include<string.h>
int main()
{
    long long n,p;
    scanf("%lld%lld",&n,&p);
    long long ans=1;
    while(n!=0)
    {
        ans*=n;
        ans%=p;
        n--;
    }
    printf("%lld\n",ans);
    return 0;
}
