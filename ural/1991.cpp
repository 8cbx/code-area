#include<stdio.h>
#include<stdlib.h>
int main()
{
    int s=0,sum=0,x;
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&x);
            if(x<m)
            {
                s+=(m-x);
            }
            if(x>m)
            {
                sum+=(x-m);
            }
        }
        printf("%d %d\n",sum,s);
    }
    return 0;
}
