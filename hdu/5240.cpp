#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct data
{
    int r,e,l,ok;
}da[100010];
int cmp(data a,data b)
{
    return a.e<b.e;
}
int main()
{
    int t,cases=0;
    int n;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&da[i].r,&da[i].e,&da[i].l);
            da[i].ok=0;
        }
        sort(da+1,da+1+n,cmp);
        int now=0,res=0;
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            if(now+(da[i].r-res)<=da[i].e)
            {
                da[i].ok=0;
                res=da[i].e-now-(da[i].r-res);
                now=da[i].e+da[i].l;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            printf("Case #%d: NO\n",cases);
        }
        else printf("Case #%d: YES\n",cases);
    }
    return 0;
}
