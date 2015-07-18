#include<stdio.h>
#include<string.h>
int main()
{
    long long coun=0;
    long long n;
    scanf("%lld",&n);
    coun+=n/2LL;
    coun+=n/3LL;
    coun+=n/5LL;
    coun+=n/7LL;
    coun-=n/(2LL*3LL);
    coun-=n/(2LL*5LL);
    coun-=n/(2LL*7LL);
    coun-=n/(5LL*3LL);
    coun-=n/(7LL*3LL);
    coun-=n/(5LL*7LL);
    coun+=n/(2LL*3LL*5LL);
    coun+=n/(2LL*3LL*7LL);
    coun+=n/(7LL*3LL*5LL);
    coun+=n/(2LL*7LL*5LL);
    coun-=n/(2LL*3LL*5LL*7LL);
    printf("%lld\n",n-coun);
    return 0;
}
