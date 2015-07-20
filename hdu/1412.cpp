#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    int a[10000*2+10];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<n+m;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n+m);
        int b[10000*2+5];
        memset(b,0,sizeof(b));
        b[0]=a[0];
        int now=0;
        for(int i=1;i<n+m;i++)
        {
            if(a[i]!=b[now])
            {
                now++;
                b[now]=a[i];
            }
        }
        for(int i=0;i<now;i++)
        {
            printf("%d ",b[i]);
        }
        printf("%d\n",b[now]);
    }
    return 0;
}
