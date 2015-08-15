#include<stdio.h>
#include<string.h>
int a[100010];
void init()
{
    a[0]=0;
    a[1]=1;
    for(int i=1;i<=100000/2;i++)
    {
        a[2*i]=a[i];
        a[2*i+1]=a[i]+a[i+1];
    }
    for(int i=1;i<=100000;i++)
    {
        if(a[i]>a[i+1])
        {
            a[i+1]=a[i];
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    init();
    while(t--)
    {
        int tmp;
        scanf("%d",&tmp);
        printf("%d\n",a[tmp]);
    }
    return 0;
}
