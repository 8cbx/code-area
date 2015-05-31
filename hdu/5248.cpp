#include<stdio.h>
#include<string.h>
int a[100010],up[100010],down[100010],n;
int test(int ch)
{
    for(int i=1;i<=n;i++)
    {
        up[i]=a[i]+ch;
        down[i]=a[i]-ch;
        if(i>1&&down[i]<=down[i-1])
        {
            down[i]=down[i-1]+1;
        }
        if(down[i]>up[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int l,r;
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        int cases=0;
        while(t--)
        {
            cases++;
            scanf("%d",&n);
            for(int i=1;i<=n;i++)
            {
                scanf("%d",&a[i]);
            }
            l=0;
            r=1000000;
            while(l<=r)
            {
                int mid=(l+r)/2;
                int ans=test(mid);
                if(ans==1)
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            printf("Case #%d:\n",cases);
            printf("%d\n",l);
        }
    }
    return 0;
}
