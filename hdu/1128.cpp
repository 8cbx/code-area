#include<stdio.h>
#include<string.h>
int a[1000010];
int main()
{
    memset(a,0,sizeof(a));
    for(int i=1;i<=1000000;i++)
    {
        int sum=i;
        int tmp=i;
        while(tmp>0)
        {
            sum+=tmp%10;
            tmp/=10;
        }
        if(sum<=1000000)a[sum]=1;
    }
    for(int i=1;i<=1000000;i++)
    {
        if(a[i]==0)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}
