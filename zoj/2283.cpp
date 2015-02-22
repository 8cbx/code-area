#include<stdio.h>
#include<string.h>
#include<algorithm>
#define INF 999999999
#define maxx(a,b) a>b?a:b
using namespace std;
struct poss
{
    int x,y;
}pos[100010];
int n,m,p;
int d[100010],s[100010];

int cmp(poss a,poss b)
{
    if(a.x==b.x)
    {
        return a.y<b.y;
    }
    else
    {
        return a.x<b.x;
    }
}

void dp()
{
    int temp,l,r,mid,ans,top;
    ans=0;
    s[1]=pos[1].y;
    top=1;
    d[1]=1;
    for(int i=2;i<=p;i++)
    {
        if(pos[i].y<s[top])
        {
            top++;
            s[top]=pos[i].y;
            d[i]=top;
        }
        else
        {
            l=1;
            r=top;
            while(l<=r)
            {
                mid=(l+r)/2;
                if(s[mid]<=pos[i].y)
                {
                    temp=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            s[temp]=pos[i].y;
            d[i]=temp;
        }
        if(ans<d[i])
        {
            ans=d[i];
        }
    }
    printf("%d\n",ans);
}

int main()
{
    while(scanf("%d%d%d",&n,&m,&p)!=EOF)
    {
        for(int i=1;i<=p;i++)
        {
            scanf("%d%d",&pos[i].x,&pos[i].y);
        }
        sort(pos+1,pos+p+1,cmp);
        dp();
    }
    return 0;
}
