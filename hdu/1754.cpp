#include<cstdio>
#include<algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=222222;
int sum[maxn<<2];
void Pushup(int rt)
{
    sum[rt]=max(sum[rt<<1],sum[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&sum[rt]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    Pushup(rt);
}
void update(int p,int sc,int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]=sc;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m)
    {
        update(p,sc,lson);
    }
    else
    {
        update(p,sc,rson);
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
    if(L<=m)ret=max(ret,query(L,R,lson));
    if(R>m)ret=max(ret,query(L,R,rson));
    return ret;
}
int main()
{
    int n,m,l,r;
    char s[2];
    while(scanf("%d%d",&n,&m) !=EOF)
    {
        build(1,n,1);
        while(m--)
        {
            scanf("%s%d%d",s,&l,&r);
            if(s[0]=='Q')
            {
                printf("%d\n",query(l,r,1,n,1));
            }
            else
            {
                update(l,r,1,n,1);
            }
        }
    }
    return 0;
}
