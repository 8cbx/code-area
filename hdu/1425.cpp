#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int a[1000010];
int main()
{
    int n,m;
    int i;
    //a[0]=-500001;
    while(scanf("%d%d",&n,&m)!=EOF){
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(i=n;i>=n-m+1;i--)
    {
        if(i!=n)
            printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");}
    return 0;
}
