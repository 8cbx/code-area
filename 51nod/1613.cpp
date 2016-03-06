#include<stdio.h>
#include<string.h>
int main()
{
    long long a,b;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        if(a%2==1)
        {
            if(b%2==0)
            {
                puts("-1");
            }
            else
            {
                long long ans=a/b;
                if(a%b!=0)
                    ans++;
                if(ans%2==0)
                    ans++;
                printf("%lld\n",ans);
            }
        }
        else
        {
            if(b%2==0)
            {
                if(a/2<b&&b<a-1)
                {
                    puts("3");
                }
                else
                {
                    long long ans=a/b;
                    if(a%b!=0)
                        ans++;
                    printf("%lld\n",ans);
                }
            }
            else
            {
                if(a/2<b&&b<=a-1)
                {
                    long long ans=a/(a-b);
                    if(a%(a-b)!=0)
                        ans++;
                    if(ans%2!=0)
                        ans++;
                    printf("%lld\n",ans);
                }
                else
                {
                    long long ans=a/b;
                    if(a%b!=0)
                        ans++;
                    if(ans%2!=0)
                        ans++;
                    printf("%lld\n",ans);
                }
            }
        }
    }
    return 0;
}

