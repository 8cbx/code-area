#include<stdio.h>
#include<stdlib.h>
int gcd(long long int a,long long int b)
{
    if(a<b)
    {
        long long int temp;
        temp=a;
        a   =b;
        b   =temp;
    }
    if(b==0)
    {
        return a;
    }
    else gcd(b,a%b);
}
int main()
{
    //freopen("1","r",stdin);
    //freopen("2","w",stdout);
    long long int a,b,c,n,t;
    scanf("%I64d",&n);
    while(n--)
    {
        scanf("%I64d",&t);
        scanf("%I64d",&a);
        t--;
        while(t--)
        {
            scanf("%I64d",&b);
            c=gcd(a,b);
            a=a*(b/c);
            //printf("--%I64d\n",a);
        }
        printf("%I64d\n",a);
    }
    return 0;
}
