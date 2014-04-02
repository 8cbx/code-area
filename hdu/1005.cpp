#include<stdio.h>
#include<stdlib.h>
int f[100];
int main()
{
    int i,j,k;
    int n;
    int a,b;
    f[1]=1;
    f[2]=1;
    while(scanf("%d%d%d",&a,&b,&n)!=EOF)
    {
        if(a==b&&a==0&&a==n)break;
        for(i=3;i<=50;i++)
        {
            f[i]=(a*f[i-1]+b*f[i-2])%7;
        }
        printf("%d\n",f[n%48]);
    }
    return 0;
}
