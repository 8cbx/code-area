#include<stdio.h>
#include<string.h>
#include<math.h>
long long eular(long long n)
{
    long long ans = n;
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            ans -= ans/i;
            while(n % i == 0)
                n /= i;
        }
    }
    if(n > 1)ans -= ans/n;
    return ans;
}
int main()
{
    long long n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
    printf("%lld\n",eular(n+1));
    }
    return 0;
}
