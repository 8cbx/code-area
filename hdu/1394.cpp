#include<cstdio>
#include<algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=5010;
int sum[maxn<<2];
void Pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt)
{
    sum[rt]=0;
    if(l==r)
    {
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    Pushup(rt);
}
void update(int p,int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]++;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m)
    {
        update(p,lson);
    }
    else
    {
        update(p,rson);
    }
    Pushup(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r)
    {
        return sum[rt];
    }
    int m=(l+r)>>1;
    int ret=0;
    if(L<=m)ret+=query(L,R,lson);
    if(R>m)ret+=query(L,R,rson);
    return ret;
}
int s[maxn];
int main()
{
    int n,i,j,t,l,r,sum=0;
    while(scanf("%d",&t)!=EOF)
    {
        sum=0;
        build(0,t-1,1);
        for(i=1;i<=t;i++)
        {
            scanf("%d",&s[i]);
            sum+=query(s[i],t-1,0,t-1,1);
            update(s[i],0,t-1,1);
        }
        int ret=sum;
        for(i=1;i<=t;i++)
        {
            sum+=t-s[i]-s[i]-1;
            ret=min(ret,sum);
        }
        printf("%d\n",ret);
    }
    return 0;
}
