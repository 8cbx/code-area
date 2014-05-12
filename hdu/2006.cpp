#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,sum,temp;
    while(scanf("%d",&n)!=EOF)
    {
        sum=1;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&temp);
            if(temp%2==1)
            {
                sum*=temp;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
