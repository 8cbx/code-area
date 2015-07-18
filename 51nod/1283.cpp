#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    long long n;
    int ans=99999999;
    int lon;
    scanf("%lld",&n);
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            lon=(i+n/i)*2;
            if(lon<ans)
            {
                ans=lon;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
