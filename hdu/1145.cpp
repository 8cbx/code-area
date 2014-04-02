#include<stdio.h>
#include<string.h>
double f[30]={1};
double t;

double maxx(double a,double b)
{
    return a>b?a:b;
}

double clc(double a,double b,double c)
{
    double top=-0.5*b/a;
    if(top>=t&&top<=1)return c-0.25*b*b/a;
    else return maxx(a*t*t+b*t+c,a+b+c);
}

int main()
{
    int i,j,a;
    while(scanf("%d%lf",&a,&t)!=EOF)
    {
        if(a==0)
        {
            break;
        }
        for(i=1;i<=a;i++)
        {
            f[i]=clc(f[i-1]/(t-1),1.0/(1-t),(f[i-1]-t)/(1-t));
        }
        printf("%.3lf\n",f[a]);
    }
    return 0;
}
