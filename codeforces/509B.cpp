#include<stdio.h>
#include<string.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
int main()
{
    int a[110];
    int n,i,k;
    int maxx,minn;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&k);
        maxx=-1;
        minn=101;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            maxx=max(maxx,a[i]);
            minn=min(minn,a[i]);
        }
        if(maxx-minn>k)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
            for(i=1;i<=n;i++)
            {
                int num=1;
                for(int j=1;j<=a[i];j++)
                {
                    if(num>k)
                    {
                        num=num%k;
                    }
                    if(num%k==0)
                    {
                        num=num%k+k;
                    }
                    if(j==1)
                    {
                        printf("%d",num);
                    }
                    else printf(" %d",num);
                    num++;
                }
                printf("\n");
            }
        }
    }
    return 0;
}
