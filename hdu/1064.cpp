#include<stdio.h>
#include<stdlib.h>
int main()
{
    double s;
    int i;
    double ans=0;
    for(i=1;i<=12;i++)
    {
        scanf("%lf",&s);
        ans+=s;
    }
    printf("$%.2lf\n",ans/12);
    return 0;
}
