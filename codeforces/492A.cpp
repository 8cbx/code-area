#include<stdio.h>
#include<string.h>
int n[10010];
int  sum[10010];
void init()
{
    sum[1]=1;
    for(int i=2;i<=10000;i++)
    {
        sum[i]+=sum[i-1]+(1+i)*i/2;
    }
}
int main()
{
    int nn;
    scanf("%d",&nn);
    init();
    for(int i=1;i<=10000;i++)
    {
        if(sum[i]==nn)
        {
            printf("%d\n",i);
            break;
        }
        if(sum[i]>nn)
        {
            printf("%d\n",i-1);
            break;
        }
    }
    return 0;
}
