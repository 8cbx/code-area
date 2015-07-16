#include<stdio.h>
#include<string.h>
int main()
{
    long long a[50010];
    int n;
    scanf("%d",&n);
    a[0]=0LL;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    long long min=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
        }
    }
    if(min>0)
    {
        min=0;
    }
    printf("%lld\n",-min);
    return 0;
}
