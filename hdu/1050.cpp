#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j,k;
    int line[210];
    int a,b;
    int n,m,t,maxx;
    int temp;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        maxx=0;
        memset(line,0,sizeof(line));
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
            scanf("%d%d",&a,&b);
            if(a>b)
            {
                temp=a;
                a=b;
                b=temp;
            }
            for(k=(a+1)/2;k<=(b+1)/2;k++)
            {
                line[k]++;
                if(line[k]>maxx)
                    maxx=line[k];
            }
        }
        printf("%d\n",maxx*10);
    }
    return 0;
}
