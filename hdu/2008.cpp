#include<stdio.h>
#include<string.h>
int main()
{
    int zheng,fu,ling;
    double temp;
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        zheng=fu=ling=0;
        for(i=1; i<=n; i++)
        {
            scanf("%lf",&temp);
            if(temp>0)
            {
                zheng++;
            }
            else if(temp<0)
            {
                fu++;
            }
            else ling++;
        }
        printf("%d %d %d\n",fu,ling,zheng);
    }
    return 0;
}
