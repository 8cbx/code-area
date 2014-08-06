#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    double pi=acos(-1.0);
    int t,now=1;
    scanf("%d",&t);
    double n,m,tt,c,a[5],eps=10e-9;
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&n,&m,&tt,&c);
        a[0]=tt*tt*n*m;
        a[1]=(c*(tt-c)+c*c/4.0)*4+n*m*(tt-c)*(tt-c)+c*(n+m-4)*(tt-c);
        a[2]=2*(tt-c)*c*n*m-c*(n+m)*(tt-c)+c*c*(n+m-2);
        a[4]=pi*c*c/4.0*(n-1)*(m-1);
        a[3]=a[0]-a[1]-a[2]-a[4];
        printf("Case %d:\n",now++);
        printf("Probability of covering 1 tile  = %.4lf%%\n",a[1]/a[0]*100.0+eps);
        printf("Probability of covering 2 tiles = %.4lf%%\n",a[2]/a[0]*100.0+eps);
        printf("Probability of covering 3 tiles = %.4lf%%\n",a[3]/a[0]*100.0+eps);
        printf("Probability of covering 4 tiles = %.4lf%%\n",a[4]/a[0]*100.0+eps);
        printf("\n");
    }
    return 0;
}
