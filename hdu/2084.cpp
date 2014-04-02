#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int a[105][105];
    int n,i,j;
    //int l,r,m;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(i=n-1;i>0;i--)
        {
            for(j=1;j<=n;j++)
            {
                a[i][j]+=a[i+1][j]>a[i+1][j+1]?a[i+1][j]:a[i+1][j+1];
            }
        }
        printf("%d\n",a[1][1]);
    }
    return 0;
}
