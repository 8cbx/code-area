#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int a[150];
    int b[150];
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n+m==0)
        {
            return 0;
        }
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1; i<=m; i++)
        {
            scanf("%d",&b[i]);
        }
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        int flag=0,flag2=0;;
        i=1;
        j=1;
        while(i<=n&&j<=m)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else if(a[i]<b[j])
            {
                flag2=1;
                printf("%d ",a[i]);
                i++;
                flag=1;
            }
            else j++;
        }
        if(i<=n)
        {
            while(i<=n)
            {
                flag2=1;
                flag=1;
                printf("%d ",a[i]);
                i++;
            }
        }
        if(flag==0)
        {
            printf("NULL");
        }
        printf("\n");
    }
    return 0;
}
