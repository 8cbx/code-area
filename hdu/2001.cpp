#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    double a,b,c,d;
    double length;
    while(scanf("%lf%lf%lf%lf",&a,&b,&c,&d)!=EOF)
    {
        length=sqrt((a-c)*(a-c)+(b-d)*(b-d));
        printf("%.2lf\n",length);
    }
    return 0;
}
