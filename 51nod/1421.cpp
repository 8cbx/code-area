#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int a[200010];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    a[0]=0;
    int maxx=0;
    for(int i=1;i<=n;i++)
    {
        int muti=2;
        while(a[i]*(muti-1)<a[n])
        {
            int last=lower_bound(a+1,a+1+n,a[i]*muti)-a;
            last--;
            //printf("--%d\n",last);
            if(a[last]%a[i]>maxx)
            {
                maxx=a[last]%a[i];
            }
            muti++;
        }
    }
    printf("%d\n",maxx);
    return 0;
}
