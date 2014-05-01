#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,c,x;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        x=a>b?b:a;
        x=x>c?c:x;
        if(x<=168)
        {
            printf("CRASH %d\n",x);
        }
        else printf("NO CRASH\n");
    }
    return 0;
}
