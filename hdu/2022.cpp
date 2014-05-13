#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int i,j,n,m,temp,x,y,maxx,maxxabs;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        maxx=-1;
        maxxabs=-1;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                scanf("%d",&temp);
                if((int)fabs(temp)>maxxabs)
                {
                    maxx=temp;
                    maxxabs=(int)fabs(temp);
                    x=i;
                    y=j;
                }
            }
        }
        printf("%d %d %d\n",x,y,maxx);
    }
    return 0;
}
