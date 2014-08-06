#include<stdio.h>
#include<string.h>
int main()
{
    int a[250][250];
    int i,j,k;
    int now,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(0));
        for(i=1;i<=2*n+1;i++)
        {
            now=i;
            for(j=1;j<=2*n+1;j++)
            {
                if(i==j)
                {
                    a[i][j]=0;
                    now++;
                    if(now>(2*n+1))
                    {
                        now=1;
                    }
                }
                else
                {
                    a[i][j]=now;
                    now++;
                    if(now>(2*n+1))
                    {
                        now=1;
                    }
                }
            }
        }
        for(i=1;i<=2*n+1;i++)
        {
            for(j=1;j<=2*n+1;j++)
            {
                printf("%d",a[i][j]);
                if(j==(2*n+1))
                {
                    printf("\n");
                }
                else printf(" ");
            }
        }
    }
    return 0;
}
