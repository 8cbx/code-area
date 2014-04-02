#include<stdio.h>
int main()
{
    int a,b,i,n,m,t;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            scanf("%d%d",&n,&m);
            a=0;
            for(i=1;i<=n*m;i++)
            {
                scanf("%d",&b);
                if(b==1)a++;
            }
            printf("%d\n",a);
        }
    }
    return 0;
}
