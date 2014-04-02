#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c,n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        b=a%4+3;
        a=a%10;
        c=a;
        for(int i=1;i<=b;i++)
        {
            c=a*c;
            c%=10;
        }
        printf("%d\n",c);
    }
    return 0;
}
