#include<stdio.h>
#include<string.h>
int main()
{
    long long a,sum,n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        a=0;
        sum=0;
        long long temp;
        for(int i=1; i<=n; i++)
        {
            scanf("%I64d",&temp);
            if(temp>a)
            {
                a=temp;
            }
            sum+=temp;
        }
        if(sum-a+1>=a)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
