#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int a[100010];
    int n;
    int sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=sum)
        {
            sum+=a[i];
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
