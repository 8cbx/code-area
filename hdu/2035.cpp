#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c;
    while(scanf("%d%d",&a,&b)!=EOF&&!(a==0&&b==0))
    {
        a%=1000;
        c=1;
        while(b--)
        {
            c*=a;
            c%=1000;
        }
        //c%=1000;
        printf("%d\n",c);
    }
    return 0;
}
