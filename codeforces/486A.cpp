#include<stdio.h>
#include<string.h>
int main()
{
    long long n;
    while(scanf("%I64d",&n)!=EOF)
    {
        if(n%2==0)
        {
            printf("%I64d\n",n/2);
        }
        else printf("-%I64d\n",(n+1)/2);
    }
}
