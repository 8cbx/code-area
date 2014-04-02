#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max(a,b) a>b?a:b
const double pi=acos(-1.0);
const int maxn=10000+5;
int n,f;
double A[maxn];

bool ok(double area)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=floor(A[i]/area);
    }
    return sum>=f+1;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&f);
        double maxa=-1;
        for(int i=0;i<n;i++)
        {
            int r;
            scanf("%d",&r);
            A[i]=pi*r*r;
            maxa=max(maxa,A[i]);
        }
        double L=0,R=maxa;
        while(R-L>1e-5)
        {
            double M=(L+R)/2;
            if(ok(M))L=M;else R=M;
        }
        printf ("%.4lf\n",L);
    }
    return 0;
}
