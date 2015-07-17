#include<stdio.h>
#include<string.h>
int main()
{
    int is[500000];
    int now=1;
    for(int i=1;i<=1000000000;now++)
    {
        is[now]=i;
        i+=now;
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x;
        scanf("%d",&x);
        for(int i=1;i<=now+1;i++)
        {
            if(is[i]>x)
            {
                printf("0\n");
                break;
            }
            if(is[i]==x)
            {
                printf("1\n");
                break;
            }
        }
    }
    return 0;
}
