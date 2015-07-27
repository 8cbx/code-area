#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct data
{
    int x,a;
}a[100010];
long long sumlenl[100010];
long long sumlenr[100010];
int sumappl[100010];
int sumappr[100010];
int main()
{
    int l,n,k;
    //int x[100010],a[100010];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(sumlenl,0,sizeof(sumlenl));
        memset(sumlenr,0,sizeof(sumlenr));
        int left=0,right=0;
        long long ans=0;
        scanf("%d%d%d",&l,&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].a);
            for(int j=0;j<a[i].a;j++)
            {
                if(a[i].x*2<l)
                    sumappl[++left]=a[i].x;
                else
                    sumappr[++right]=l-a[i].x;
            }
        }
        sort(sumappl+1,sumappl+left+1);
        sort(sumappr+1,sumappr+right+1);
        for(int i=1;i<=left;i++)
        {
            if(i<=k)
            {
                sumlenl[i]=sumappl[i];
            }
            else
            {
                sumlenl[i]=sumlenl[i-k]+sumappl[i];
            }
        }
        for(int i=1;i<=right;i++)
        {
            if(i<=k)
            {
                sumlenr[i]=sumappr[i];
            }
            else
            {
                sumlenr[i]=sumlenr[i-k]+sumappr[i];
            }
        }
        ans=(sumlenl[left]+sumlenr[right])*2;
        for(int i=0;i<=k;i++)
        {
            long long ll=(sumlenl[left-i]+sumlenr[max(0,right-(k-i))])*2;
            ans=min(ans,l+ll);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
