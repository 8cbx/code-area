#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;
int cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    int n;
    long long p;
    long long a[100010];
    while(scanf("%d%I64d",&n,&p)!=EOF)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%I64d",&a[i]);
            a[i]%=p;
        }
        sort(a+1,a+1+n,cmp);
        long long max=0;
        for(int i=1; i<n; i++)
        {
            if(a[i]+a[i+1]>=p)
            {
                if((a[i]+a[i+1])%p>max)
                {
                    max=(a[i]+a[i+1])%p;
                }
                int l=i+1;
                int r=n;
                while(l<r)
                {
                    int mid=(l+r)/2;
                    if(a[i]+a[mid]>=p)
                    {
                        l=mid+1;
                    }
                    else
                    {
                        r=mid;
                    }
                    //printf("yes\n");
                }
                //printf("%d\n",r);
                if((a[i]+a[r])%p>max)
                {
                    max=(a[i]+a[r])%p;
                }
            }
            else
            {
                if((a[i]+a[i+1])%p>max)
                {
                    max=(a[i]+a[i+1])%p;
                }
            }
        }
        printf("%I64d\n",max);
    }
    return 0;
}
