#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(a>b-c)
            {
                printf("do not advertise\n");
            }
            else if(a<b-c)
            {
                printf("advertise\n");
            }
            else printf("does not matter\n");
        }
    }
    return 0;
}
