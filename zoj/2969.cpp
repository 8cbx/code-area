#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j;
    int n,a[150];
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            scanf("%d",&n);
            n++;
            for(i=1;i<=n;i++)
            {
                scanf("%d",&a[i]);
            }
            j=n-1;
            for(i=1;i<n-1;i++)
            {
                printf("%d ",a[i]*j);
                j--;
            }
            printf("%d\n",a[n-1]);
        }
    }
    return 0;
}
