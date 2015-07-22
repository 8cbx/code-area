#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct data
{
    double coun;
    int id;
}a[1000010];
int cmp(data a,data b)
{
    return a.coun>b.coun;
}
int cmp2(data a,data b)
{
    return a.id>b.id;
}
int main()
{
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        memset(a,0,sizeof(a));
        double tmp;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%lf",&tmp);
                a[j].coun+=tmp;
                a[j].id=j;
            }
        }
        sort(a+1,a+1+m,cmp);
        sort(a+1,a+1+k,cmp2);
        for(int i=1;i<k;i++)
        {
            printf("%d ",a[i].id);
        }
        printf("%d\n",a[k].id);
    }
    return 0;
}
