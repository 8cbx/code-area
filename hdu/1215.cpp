#include<stdio.h>
#include<string.h>
#include<math.h>
int a[500010];
int main()
{
    int n;
    int temp,ans,i,j,t=0;
    memset(a,0,sizeof(a));
    for(i=1; i<=500000; i++)
    {
        for(j=i+i; j<=500000; j+=i)
        {
            a[j]+=i;
        }
    }
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            scanf("%d",&n);
            printf("%d\n",a[n]);
        }

    }
    return 0;
}
