#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,a[500010];
    int ans=0;
    int now=0;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    now=n/2;
    for(int i=n-1;i>=n/2;i--)
    {
        for(int j=now;j>0;j--)
        {
            if(2*a[j-1]<=a[i]&&a[j-1]!=0)
            {
                a[j-1]=0;
                a[i]=0;
                ans++;
                now=j;
                break;
            }
        }
    }
    printf("%d\n",n-ans);
    return 0;
}
