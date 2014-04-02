#include<stdio.h>
#include<stdlib.h>
int a[1000010];
int main()
{
    int b,n,i;
    a[0]=7;
    a[1]=11;
    for(i=2;i<=1000000;i++)
    {
        a[i]=a[i-1]%3+a[i-2]%3;
    }
    while(scanf("%d",&b)!=EOF)
    {
        if(a[b]%3==0)
        {
            printf("yes\n");
        }
        else printf("no\n");
    }
    return 0;
}
