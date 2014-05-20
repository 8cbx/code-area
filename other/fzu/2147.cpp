#include<stdio.h>
#include<string.h>
int main()
{
    int t,coun;
    long long a,b;
    int i;
    while(scanf("%d",&t)!=EOF)
    {
        i=0;
        while(t--)
        {
            i++;
            coun=0;
            printf("Case %d: ",i);
            scanf("%I64d%I64d",&a,&b);
            while(a>b)
            {
                coun++;
                if(a%2==0)
                {
                    a=a-(a-1)/2;
                }
                else
                {
                    a=a-a/2;
                }
                //printf("%lld %lld\n",a,b);
            }
            printf("%d\n",coun);
        }
    }
    return 0;
}
