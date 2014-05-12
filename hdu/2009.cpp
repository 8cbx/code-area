#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    double root,sum;
    int n,i;
    while(scanf("%lf%d",&root,&n)!=EOF)
    {
        sum=0;
        for(i=1;i<=n;i++)
        {
            sum+=root;
            root=sqrt(root);
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}
