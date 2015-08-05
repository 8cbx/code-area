#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;
map<int,int>mp;
map<int,int>::iterator l;
int main()
{
    long long a[1010];
    int n;
    int cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        mp[a[i]]=1;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            long long tmp=-(a[i]+a[j]);
            l=mp.find(tmp);
            if(l!=mp.end()&&a[i]<a[j]&&a[j]<tmp)
            {
                printf("%lld %lld %lld\n",a[i],a[j],tmp);
                cnt=1;
            }
        }
    }
    if(cnt==0)
    {
        printf("No Solution\n");
    }
    return 0;
}
