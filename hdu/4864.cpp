#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct point
{
    int x,y;
} points;
int cmp(point a,point b)
{
    if(a.x==b.x)
    {
        return a.y>b.y;
    }
    return a.x>b.x;
}
int main()
{
    int n,m,xi,yi;
    int i,j,k;
    point a[100005],b[100005];
    int c[105];
    long long sum,ans;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        sum=0;
        ans=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(i=1; i<=n; i++)
        {
            scanf("%d%d",&xi,&yi);
            a[i].x=xi;
            a[i].y=yi;
        }
        for(i=1; i<=m; i++)
        {
            scanf("%d%d",&xi,&yi);
            b[i].x=xi;
            b[i].y=yi;
        }
        sort(a+1,a+1+n,cmp);
        sort(b+1,b+1+m,cmp);
        j=1;
        for(i=1;i<=m;i++)
        {
            while(j<=n&&a[j].x>=b[i].x)
            {
                c[a[j].y]++;
                j++;
            }
            for(k=b[i].y;k<=100;k++)
            {
                if(c[k]!=0)
                {
                    ans++;
                    c[k]--;
                    sum+=500*b[i].x+2*b[i].y;
                    break;
                }
            }
        }
        printf("%I64d %I64d\n",ans,sum);
    }
    return 0;
}
