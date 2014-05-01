#include<stdio.h>
#include<math.h>
const double pi=3.1415927;
int main()
{
    double ti;
    double r;
    while(scanf("%lf",&r)!=EOF)
    {
        ti=4.0/3.0*pi*r*r*r;
        printf("%.3lf\n",ti);
    }
    return 0;
}
