#include<stdio.h>
#include<string.h>
int main()
{
    int a[150];
    int n,temp,k;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&temp);
            a[temp]++;
        }
        int sum=0,now=0;
        scanf("%d",&k);
        for(int i=1;i<=100;i++)
        {
            if(a[i]>1)
            {
                sum+=a[i]-1;
                now++;
            }
            else if(a[i]==1)
            {
                now++;
            }
        }
        //printf("%d %d\n",now,sum);
        if(sum>=k)
        {
            printf("%d\n",now);
        }
        else
        {
            printf("%d\n",now-k+sum);
        }
    }
    return 0;
}
