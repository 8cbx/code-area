#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int a[10010],b[10010];
    int i,j,k,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        for(i=1;i<=(n+1)/2;i++)
        {
            if((n-i+1)!=i)
            {
                printf("%d %d",a[n-i+1],a[i]);
            }
            else printf("%d",a[n-i+1]);
            if(i!=(n+1)/2)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
