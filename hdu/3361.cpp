#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a;
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&a);
        printf("%c",(char)a);
    }
    return 0;
}
