#include<string.h>
#include<stdio.h>
int main()
{
    int n;
    long long sum,tmp,a;
    scanf("%d",&n);
    sum=0LL;
    tmp=0LL;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a);
        if(tmp>0)
        {
            tmp+=a;
        }
        else tmp=a;
        if(tmp>sum)
        {
            sum=tmp;
        }
    }
    printf("%lld\n",sum);
    return 0;
}
