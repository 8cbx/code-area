#include<stdio.h>
#include<string.h>
int guys[510];
int main()
{
    int n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(guys,0,sizeof(guys));
        int tmp,time;
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&tmp,&time);
            guys[tmp]+=time;
        }
        int now=0;
        int sta=1;
        int ans=0;
        while(sta<=500)
        {
            //printf("%d\n",now);
            while(guys[sta]>=64)
            {
                guys[sta]-=64;
                now++;
                if(now>=36)
                {
                    ans++;
                    now=0;
                }
                //printf("%d\n",now);
            }
            if(guys[sta]!=0)now++;
            if(now>=36)
            {
                ans++;
                now=0;
            }
            //printf("%d\n",now);
            sta++;
        }
        if(now!=0)
        {
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
