#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max(a,b) a>=b?a:b
int a[1000010];
int maxn[1000010];
int f[1000010];
int main()
{

    int n,m;
    int i,j;
    int maxx;

    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            maxn[i]=0;
            f[i]=0;
        }
        maxn[0]=0;
        f[i]=0;
        for(i=1;i<=m;i++)
        {
            maxx=-99999999;
            for(j=i;j<=n;j++)
            {
                f[j]=max(f[j-1]+a[j],maxn[j-1]+a[j]);
                maxn[j-1]=maxx;
                maxx=max(f[j],maxx);
            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}
