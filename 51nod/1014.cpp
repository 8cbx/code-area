#include<stdio.h>
#include<string.h>
int main()
{
    int p,a;
    scanf("%d%d",&p,&a);
    int flag=0;
    for(long long i=0;i<=p;i++)
    {
        if((long long)(i*i)%(long long)p==(long long)a)
        {
            printf("%lld ",i);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("No Solution\n");
    }
    return 0;
}
