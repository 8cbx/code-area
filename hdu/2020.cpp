#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
int cmp(int a,int b)
{
    return (int)fabs(a)>(int)fabs(b);
}
int main()
{
    int n,i,num[150];
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        for(i=1; i<=n; i++)
        {
            scanf("%d",&num[i]);
        }
        sort(num+1,num+1+n,cmp);
        if(n==1)
        {
            printf("%d\n",num[n]);
        }
        else
        {
            for(i=1; i<n; i++)
            {
                printf("%d ",num[i]);
            }
            printf("%d\n",num[n]);
        }
    }
    return 0;
}
