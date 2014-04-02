#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i;
    int t;
    double jc[10];
    double s[12];
    jc[0]=1;
    for(i=1;i<=9;i++)
    {
        jc[i]=jc[i-1]*i;
    }
    s[0]=1;
    for(i=1;i<=9;i++)
    {
        s[i]=(1/jc[i])+s[i-1];
    }
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
    for(i=3;i<=9;i++)
    {
        printf("%d %.9lf\n",i,s[i]);
    }
    return 0;
}
