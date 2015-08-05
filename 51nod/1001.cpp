#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;
map<int,int>mp;
map<int,int>::iterator l;
int main()
{
    int k,n;
    int a[50010];
    scanf("%d%d",&k,&n);
    mp.clear();
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        mp[a[i]]=1;
    }
    int cnt=0;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        int tmp=k-a[i];
        if(tmp<=a[i])
        {
            continue;
        }
        else
        {
            l=mp.find(tmp);
            if(l!=mp.end())
            {
                printf("%d %d\n",a[i],tmp);
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
