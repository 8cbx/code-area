#include<stdio.h>
#include<string.h>
int main()
{
    int a;
    int coun=0;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        coun=0;
        while(a>0)
        {
            a/=5;
            coun+=a;
        }
        printf("%d\n",coun);
    }
    return 0;
}
