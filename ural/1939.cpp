#include<stdio.h>
#include<string.h>
int main()
{
    int l,h,H,v,x,a;
    double d1,d2;
    double exp=10e-9;
    while(scanf("%d%d%d%d%d%d",&l,&h,&H,&v,&x,&a)!=EOF)
    {
        d1=(double)(H-h)/x*v-l;
        d2=(double)v*v/2/a;
        if(d1<d2+exp)
        {
            printf("Crash\n");
        }
        else printf("Safe\n");
    }
    return 0;
}
