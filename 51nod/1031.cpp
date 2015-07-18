#include<stdio.h>
#include<string.h>
int main()
{
    long long f[1010];
    int n;
    scanf("%d",&n);
    f[1]=1LL;
    f[2]=2LL;
    for(int i=3;i<=n;i++)
    {
        f[i]=f[i-1]+f[i-2];
        f[i]%=1000000007;
    }
    printf("%lld\n",f[n]);
    return 0;
}
