#include<stdio.h>
#include<string.h>
int main()
{
    long long t,n,a,b,ans,c;
    int i=0;
    while(scanf("%lld",&t)!=EOF)
    {
        i=1;
        while(t--)
        {
            scanf("%lld",&n);
            printf("Case %d: ",i);
            i++;
            if(n%2==0)
            {
                a=n/2%1000000007;
                b=(n+1)%1000000007;
            }
            else
            {
                a=n%1000000007;
                b=(n+1)/2%1000000007;
            }
            c=a*b%1000000007;
            ans=c*c%1000000007*((c-2*n%1000000007+2)%1000000007)%1000000007;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
