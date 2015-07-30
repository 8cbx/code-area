#include<stdio.h>
#include<string.h>
int maxx;
int a[100000];
void init()
{
    //printf("+++");
    maxx=0;
    a[1]=1;
    a[2]=2;
    for(int i=3;;i++)
    {
        long long tmp=a[i-1]+a[i-2];
        if(tmp>1e9)
        {
            break;
        }
        maxx=i;
        a[i]=tmp;
    }
    //printf("---");
}
int main()
{
    init();
    int t,n;
    scanf("%d",&t);
    //printf("%d\n",maxx);
    while(t--)
    {
        scanf("%d",&n);
        int flag=0;
        for(int i=1;i<=maxx;i++)
        {
            if(a[i]==n)
            {
                flag=1;
                printf("B\n");
                break;
            }
        }
        if(flag==1)
        {
            continue;
        }
        else
        {
            printf("A\n");
        }
    }
    return 0;
}
