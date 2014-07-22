#include<stdio.h>
#include<string.h>
int main()
{
    int n,p;
    while(scanf("%d%d",&n,&p)!=EOF)
    {
        printf("%s\n",(n/(p-1))%2==0?"NO":"YES");
    }
    return 0;
}
