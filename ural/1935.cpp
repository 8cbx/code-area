#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    int a[150];
    int n,i,ans;
    while(scanf("%d",&n)!=EOF)
    {
        ans=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            ans+=a[i];
        }
        sort(a+1,a+n+1);
        ans+=a[n];
        printf("%d\n",ans);
    }
    return 0;
}
