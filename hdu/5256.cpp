#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define INF 9999999
int d[1000010];
int g[1000010];
int a[1000010];
int main()
{
    int t;
    int cases;
    int n;
    cases=0;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        int ans=0;
        memset(d,0,sizeof(d));
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            a[i]-=i;
        }
        for(int i=1; i<=n; i++)
        {
            g[i]=INF;
        }
        for(int i=0; i<n; i++)
        {
            int k=upper_bound(g+1,g+n+1,a[i])-g;
            //printf("%d\n",k);
            d[i]=k;
            g[k]=a[i];
        }
        for(int i=1; i<=n; i++)
        {
            if(g[i]!=9999999)
            {
                ans++;
            }
        }
        printf("Case #%d:\n",cases);
        printf("%d\n",n-ans);
    }
    return 0;
}
