#include<stdio.h>
#include<string.h>
int a[100];
int main()
{
    a[0]=1;
    a[1]=2;
    for(int i=2;i<=42;i++)
    {
        a[i]=a[i-1]+a[i-2]+1;
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i=0;
        if(n==0)
        {
            return 0;
        }
        while(a[i]<=n)
        {
            i++;
        }
        printf("%d\n",i-1);
    }
}
