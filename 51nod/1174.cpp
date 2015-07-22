#include<stdio.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=55555;
int sum[maxn<<2];
void Pushup(int rt)
{
    sum[rt]=sum[rt<<1]>sum[rt<<1|1]?sum[rt<<1]:sum[rt<<1|1];
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
int query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r)
    {
        return sum[rt];
    }
    int m=(l+r)>>1;
    int ret=0;
    if(L<=m)
    {
        int tmp=query(L,R,lson);
        if(ret<tmp)
        {
            ret=tmp;
        }
    }
    if(R>m)
    {
        int tmp=query(L,R,rson);
        if(ret<tmp)
        {
            ret=tmp;
        }
    }
    return ret;
}
int main()
{
    int n,l,r,q;
    scanf("%d",&n);
    build(1,n,1);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&l,&r);
        l++;
        r++;
        printf("%d\n",query(l,r,1,n,1));
    }
    return 0;
}
