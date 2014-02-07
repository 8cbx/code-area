#include<stdio.h>
#include<math.h>
#include<algorithm>
//#include<iostream.h>
using namespace std;
long long int a[1000010];
long long int c[1000010],sum;
int main()
{
    int i,j,k;
    int n,M;
    long long int ans,x1;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        M=sum/n;
        c[0]=0;
        for(i=1;i<=n;i++)
        {
            c[i]=c[i-1]+M-a[i];

        }
        sort(c+1,c+n+1);
        x1=c[n/2];
        ans=0;
        for(i=1;i<=n;i++)
        {
            ans+=abs(c[i]-x1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
