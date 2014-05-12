#include<stdio.h>
#include<string.h>
int main()
{
    int n,maxx,minn,temp,i;
    double sum;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        minn=9999999;
        maxx=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&temp);
            sum+=temp;
            if(maxx<temp)
            {
                maxx=temp;
            }
            else if(minn>temp)
            {
                minn=temp;
            }
        }
        printf("%.2lf\n",(sum-minn-maxx)/(n-2));
    }
    return 0;
}
