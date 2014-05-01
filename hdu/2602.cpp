#include<stdio.h>
#include<string.h>
int main()
{
    int d[1100];
    int v[1100];
    int c[1100];
    int i,j,n,t,vv;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            memset(d,0,sizeof(d));
            scanf("%d%d",&n,&vv);
            for(i=1;i<=n;i++)
            {
                scanf("%d",&c[i]);
            }
            for(i=1;i<=n;i++)
            {
                scanf("%d",&v[i]);
            }
            for(i=1;i<=n;i++)
            {
                for(j=vv;j-v[i]>=0;j--)
                {
                    if(d[j]<d[j-v[i]]+c[i])
                    {
                        d[j]=d[j-v[i]]+c[i];
                    }
                }
            }

                /*for(j=1;j<=vv;j++)
                {
                    printf("%d ",d[j]);

            }*/
            printf("%d\n",d[vv]);
        }
        return 0;
    }
}
