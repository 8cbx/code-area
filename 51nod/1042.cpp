#include<stdio.h>
#include<string.h>
long long a[50];
long long Count(int aa,long long n)
{
    long long flag=(long long)aa;
    long long tem,i,x,k;
    long long coun=0;
    x=n;
    k=1;
    if(flag==0)
    {
        for(i=1,k=1;n>=10;i++)
        {
            tem=n%10;
            n/=10;
            if(tem>0)
            {
                coun+=n*k;
            }
            if(tem==0)
            {
                coun+=(n-1)*k+x-(x/k)*k+1;
            }
            k*=10;
        }
        return coun;
    }
    if(n>=flag&&n<10)
    {
        return 1;
    }
    for(i=1,k=1;n>=10;i++)
    {
        tem=n%10;
        n/=10;
        if(tem>flag)
        {
            coun+=(n+1)*k;
        }
        if(tem<flag)
        {
            coun+=n*k;
        }
        if(tem==flag)
        {
            coun+=n*k+x-(x/k)*k+1;
        }
        k*=10;
    }
    if(flag)
    {
        tem=n%10;
        n=n/10;
        if(tem>flag)coun+=(n+1)*k;
        if(tem<flag)coun+=n*k;
        if(tem==flag)coun+=n*k+x-(x/k)*k+1;
        k*=10;

    }
    return coun;
}
int main()
{
    long long n,m;
    a[0]=1LL;
    for(int i=1;i<=25;i++)
    {
        a[i]=a[i-1]*10;
    }
    scanf("%lld%lld",&n,&m);
    long long j;
    for(int i=0;i<=9;i++)
    {
        j=Count(i,m)-Count(i,n-1);
        //printf("%lld--%lld\n",Count(i,m),Count(i,n-1));
        printf("%lld\n",j);
    }
    return 0;
}
