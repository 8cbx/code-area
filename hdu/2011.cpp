#include<stdio.h>
#include<math.h>
int main()
{
    int i,m,n;
    double sum;
    while(scanf("%d",&m)!=EOF)
    {
        while(m--)
        {
            scanf("%d",&n);
            sum=0;
            for(i=1;i<=n;i++)
            {
                if(i%2==1)
                {
                    sum+=1.0/i;
                }
                else sum-=1.0/i;
            }
            printf("%.2lf\n",sum);
        }
    }
    return 0;
}
