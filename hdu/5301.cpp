#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    long long n,m,x,y;
    while(scanf("%lld%lld%lld%lld",&n,&m,&x,&y)!=EOF)
    {
        if(n>m)
        {
            n^=m;
            m^=n;
            n^=m;
            x^=y;
            y^=x;
            x^=y;
        }
        if(n==1&&m==1)
        {
            printf("0\n");
            continue;
        }
        if(n==1||m==1)
        {
            printf("1\n");
            continue;
        }
        long long ans=(n+1)/2;
        if(x==y&&n==m&&(n%2)==1&&x==(n+1)/2)
        {
            ans--;
        }
        else
        {
            x=min(x,n-x+1);
            y=min(y,m-y+1);
            ans=max(ans,min(n-x,y));
            ans=min(ans,(m+1)/2);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
