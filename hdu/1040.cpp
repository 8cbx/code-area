#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[1010],b,n,i,t;
    int j;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(i=0;i<n-1;i++)
        {
            printf("%d ",a[i]);
        }
        printf("%d\n",a[n-1]);
    }
    return 0;
}
