#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n,m;
    int i,j;
    double pos;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        double ans=0;
        for(i=1;i<=n;i++)
        {
            pos=(double)i/n*(n+m);
            ans+=fabs(pos-floor(pos+0.5))/(n+m);
        }
        printf("%.4lf\n",ans*10000);
    }
    return 0;
}
