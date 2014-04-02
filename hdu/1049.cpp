#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,a,b;
    int time,now;
    while(scanf("%d%d%d",&n,&a,&b)!=EOF&&n!=0)
    {
        time=1;
        now=a;
        for(;now<n;time+=2)
        {
            now-=b;
            now+=a;
        }
        printf("%d\n",time);
    }
    return 0;
}
