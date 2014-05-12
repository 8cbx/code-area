#include<stdio.h>
#include<string.h>
int main()
{
    int num[150];
    int i,temp,minn,n,minx;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        minn=99999999;
        minx=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            if(minn>num[i])
            {
                minn=num[i];
                minx=i;
            }
        }
        num[minx]=num[1];
        num[1]=minn;
        for(i=1;i<n;i++)
        {
            printf("%d ",num[i]);
        }
        printf("%d\n",num[n]);
    }
    return 0;
}
