#include<stdio.h>
#include<string.h>
#include<math.h>
int cnt[1000010];
void getfactors(int n)
{
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            cnt[i]++;
            cnt[n/i]++;
        }
    }
}
int main()
{
    memset(cnt,0,sizeof(cnt));
    int n;
    scanf("%d",&n);
    int tmp;
    int maxx=0;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&tmp);
        if(tmp>maxx)
        {
            maxx=tmp;
        }
        getfactors(tmp);
    }
    for(int i=maxx;i>0;i--)
    {
        if(cnt[i]>=2)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}
