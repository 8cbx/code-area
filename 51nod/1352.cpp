#include<string.h>
#include<stdio.h>
long long gcd(long long a,long long b)
{
    return (b>0)?gcd(b,a%b):a;
}
void MEuclid(long long a,long long b,long long d,long long &x,long long &y)
{
    if(b==0)
    {
        d=a;
        x=1;
        y=0;
        return;
    }
    MEuclid(b,a%b,d,y,x);
    y-=x*(a/b);
}
int main()
{
    long long n,a,b;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&a,&b);
        if(a<b)
        {
            a^=b;
            b^=a;
            a^=b;
        }
        long long gcdd=gcd(a,b);
        if((n+1)%gcdd!=0)
        {
            printf("0\n");
        }
        else
        {
            long long x1,x2,y1;
            MEuclid(a,b,gcdd,x1,y1);
            x2=x1*(n+1)/gcdd;
            //long long y2=y1*(n+1)/gcdd;
            //printf("%lld %lld\n",x2,y2);
            long long res=x2%(b/gcdd);
            x2=res;
            //printf("%lld\n",res);
            //long long ans=((n+1)/a-res)/(b/gcdd);
            if(x2<=0)
            {
                x2+=b/gcdd;
            }
            long long x3=(n+1)/a;
            //printf("%lld %lld--\n",x2,x3);
            //printf("%lld %lld-+\n",a,b);
            if(x3<x2)
            {
                printf("0\n");
            }
            /*else if(x3==x2)
            {
                printf("1\n");
            }*/
            else if((n+1)%a==0)
            {
                printf("%lld\n",(x3-x2)/(b/gcdd));
            }
            else
            {
                printf("%lld\n",(x3-x2)/(b/gcdd)+1);
            }
        }
    }
    return 0;
}
