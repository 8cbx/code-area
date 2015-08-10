#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int a[25];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==k)
        {
            printf("Yes\n");
            return 0;
        }
    }
    int now=(1<<n)-1;
    while(now>0)
    {
        int tmp=now,cnt=0,wei[25];
        memset(wei,0,sizeof(wei));
        while(tmp>0)
        {
            wei[cnt]=tmp%2;
            cnt++;
            tmp/=2;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(wei[i]==1)
            {
                ans+=a[i];
            }
            //printf("%d",wei[i]);
        }
        //printf("--%d\n",ans);
        if(ans==k)
        {
            printf("Yes\n");
            return 0;
        }
        now--;
    }
    printf("No\n");
    return 0;
}
