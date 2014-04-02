#include<stdio.h>
#include<stdlib.h>
long long int gcd(long long int a,long long int b)
{
    if(b==0)
    {
        return a;
    }
    else return gcd(b,a%b);
}
int main()
{
    long long int a,b,c,d,temp;
    int n;
    long long int i,j;
    char s;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%I64d%c%I64d",&a,&s,&b);
        scanf("%I64d%c%I64d",&c,&s,&d);
        a=a*d;
        c=c*b;
        b=b*d;
        d=b;
        temp=gcd(a,c);
        a/=temp;
        a=a*c;
        temp=gcd(a,b);
        a/=temp;
        b/=temp;
        if(a/b*b!=a)printf("%I64d/%I64d\n",a,b);
        else printf("%I64d\n",a/b);
    }
    return 0;
}
