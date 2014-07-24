#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct ss
{
    int a,b;
    double c;
}now[100005];
int cmp(ss x,ss y)
{
    if(x.c==y.c)
    {
        return x.a>y.a;
    }
    return x.c>y.c;
}
int main()
{
    int i,j;
    int n;
    long long time,sum;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&now[i].a);
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&now[i].b);
            now[i].c=(double)((double)now[i].b/(double)now[i].a);
        }
        sort(now+1,now+1+n,cmp);
        time=sum=0;
        for(i=1;i<=n;i++)
        {
            time+=now[i].a;
            sum+=time*now[i].b;
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
