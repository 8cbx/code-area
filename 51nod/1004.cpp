#include<stdio.h>
#include<string.h>
int main()
{
    long long a,b,c,fina;
    int wei[50];
    scanf("%lld",&a);
    c=10LL;
    b=a;
    fina=1LL;
    int i=0;
    while(b)
    {
        wei[i++]=b%2;
        b>>=1;
    }
    for(i=i-1;i>=0;i--)
    {
        fina=fina*fina;
        fina%=c;
        if(wei[i]==1)
        {
            fina*=a;
            fina%=c;
        }
    }
    printf("%lld\n",fina);
    return 0;
}
