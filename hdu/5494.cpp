#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[510],b[510];
int cmp(int a,int b)
{
    return a<b;
}
int cmp2(int a,int b)
{
    return a>b;
}
int main()
{
    int n,m;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
        }
        sort(a+1,a+1+n,cmp);
        sort(b+1,b+1+n,cmp2);
        /*for(int i=1;i<=n;i++)
        {
            printf("%d %d\n",a[i],b[i]);
        }*/
        int ans1=0,ans2=0;
        for(int i=1;i<=m;i++)
        {
            ans1+=a[i];
            ans2+=b[i];
        }
        //printf("%d %d\n",ans1,ans2);
        if(ans1>ans2)
        {
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}
