#include<stdio.h>
#include<string.h>
long long maxsum(int *v,int n)
{
    long long sum=-999999999999;
    long long b=0;
    for(int i=1;i<=n;i++)
    {
        if(b>0)
        {
            b+=(long long)v[i];
        }
        else b=(long long)v[i];
        if(b>sum)
        {
            sum=b;
        }
    }
    return sum;
}
int main()
{
    int a[1010];
    int p;
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        long long ans=0;
        long long anss=-99999999999;
        scanf("%d%d",&n,&p);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            int tmp=a[i];
            a[i]=p;
            ans=maxsum(a,n);
            a[i]=tmp;
            if(ans>anss)
            {
                anss=ans;
            }
        }
        printf("%I64d\n",anss);
    }
    return 0;
}
