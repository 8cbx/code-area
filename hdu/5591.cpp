#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            scanf("%d",&n);
            if(n%2==0)
            {
                printf("0\n");
            }
            else
            {
                printf("1\n");
            }
        }
    }
    return 0;
}

