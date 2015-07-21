#include<string.h>
#include<stdio.h>
int main()
{
    int n;
    long long sum,tmp,a[50000+5],tmp2,sum2,sum3;
    scanf("%d",&n);
    sum=0LL;
    tmp=0LL;
    sum2=0LL;
    sum3=0LL;
    tmp2=999999999999999LL;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum3+=a[i];
        if(tmp>0)
        {
            tmp+=a[i];
        }
        else tmp=a[i];
        if(tmp>sum)
        {
            sum=tmp;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(tmp2<0)
        {
            tmp2+=a[i];
        }
        else tmp2=a[i];
        if(tmp2<sum2)
        {
            sum2=tmp2;
        }
    }
    printf("%lld\n",sum>(sum3-sum2)?sum:(sum3-sum2));
    return 0;
}
