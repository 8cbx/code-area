#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,c,d,e,f;
    while(scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)!=EOF)
    {
        int len=a+b+c;
        printf("%d\n",len*len-a*a-c*c-e*e);
    }
    return 0;
}
