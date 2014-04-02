#include<stdio.h>
#include<algorithm>
using namespace std;
int cp(int a,int b)
{
    return a>b;
}
int main()
{
    int a[55],i,j,k,l,coun,flag;
    int n;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1,cp);
    if(k<=n)
    {
        for(i=1;i<=k;i++)
        {
            printf("1 %d\n",a[i]);
        }
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            printf("1 %d\n",a[i]);
        }
        coun=n;
        flag=0;
        for(i=2;i<=n;i++)
        {
            for(j=i;j<=n;j++)
            {
                printf("%d",i);
                for(l=1;l<i;l++)
                {
                    printf(" %d",a[l]);
                }
                printf(" %d\n",j);
                coun++;
                if(coun>=k)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                break;
            }
        }
    }
    return 0;
}
