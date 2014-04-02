#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,coun,n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        a=0;
        coun=0;
        while(n--)
        {
            scanf("%d",&b);
            if(b>a)
            {
                coun+=(b-a)*6;
                a=b;
            }
            else
            {
                coun+=(a-b)*4;
                a=b;
            }
            coun+=5;
        }
        printf("%d\n",coun);
    }
    return 0;
}
