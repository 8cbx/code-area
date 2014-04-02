#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b;
    int i,j;
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        a=(a+3)/4*4;
        for(i=1;i<=b;)
        {
            if((a%4==0&&a%100!=0)||a%400==0)
            {
                i++;
            }
            a+=4;
        }
        printf("%d\n",a-4);
    }
    return 0;
}
