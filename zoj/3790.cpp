#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct point
{
    int c,p;
}a[100010];
int cmp(point x,point y)
{
    if(x.c==y.c)
        return x.p<y.p;
    return x.c<y.c;
}
int maxx(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int m,n;
    int i,j;
    int ans,tmp,now,nk,nl;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i].c);
            a[i].p=i;
        }
        sort(a+1,a+1+n,cmp);
        ans=tmp=now=nl=1;
        nk=m;
        for(i=2;i<=n;i++)
        {
            if(a[i].c==a[i-1].c)
            {
                nk-=a[i].p-a[i-1].p-1;
                now++;
                while(nk<0)
                {
                    nk+=a[nl+1].p-a[nl].p-1;
                    nl++;
                    now--;
                }
                tmp=maxx(tmp,now);
            }
            else
            {
                ans=maxx(tmp,ans);
                tmp=now=1;
                nk=m;
                nl=i;
            }
        }
        ans=maxx(tmp,ans);
        printf("%d\n",ans);
    }
    return 0;
}
