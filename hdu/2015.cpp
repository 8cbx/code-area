#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,i,sum,time,flag;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        sum=0;
        time=m;
        flag=0;
        for(i=2;i<=2*n;i+=2)
        {
            sum+=i;
            time--;
            if(time==0)
            {
                if(flag==1)
                {
                    printf(" ");
                }
                printf("%d",sum/m);
                sum=0;
                time=m;
                flag=1;
            }
        }
        if(time!=m)
        {
            if(flag==1)
                {
                    printf(" ");
                }
                printf("%d",sum/(m-time));
        }
        printf("\n");
    }
    return 0;
}
