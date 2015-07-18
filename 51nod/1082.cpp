#include<stdio.h>
#include<string.h>
long long num[1000010];
int main()
{
    long long n;
    int t;
    long long m;
    memset(num,0,sizeof(num));
    for(long long i=1;i<=1000000;i++)
    {
        m=i;
        if(m%7==0)
        {
            num[i]=num[i-1];
        }
        else
        {
            int flag=0;
            while(m)
            {
                if(m%10==7)
                {
                    num[i]=num[i-1];
                    flag=1;
                    break;
                }
                m/=10;
            }
            if(flag==0)
            {
                num[i]=num[i-1]+i*i;
            }
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",num[n]);
    }
    return 0;
}
