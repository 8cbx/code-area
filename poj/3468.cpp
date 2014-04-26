#include<stdio.h>
#include<string.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=111111;
long long sum[maxn<<2];
long long col[maxn<<2];
int Pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void Pushdown(int rt,int m)
{
    if(col[rt])
    {
        col[rt<<1]+=col[rt];
        col[rt<<1|1]+=col[rt];
        sum[rt<<1]+=(m-(m>>1))*col[rt];
        sum[rt<<1|1]+=(m>>1)*col[rt];
        col[rt]=0;
    }
}
void build(int l,int r,int rt)
{
    col[rt]=0;
    if(l==r)
    {
        scanf("%lld",&sum[rt]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    Pushup(rt);
}
void update(int L,int R,int c,int l,int r,int rt)
{
    //printf("%d--%d--%d--%d--%d--%d\n",L,R,c,l,r,rt);
    if(L<=l&&R>=r)
    {
        col[rt]+=c;
        sum[rt]+=(long long )c*(r-l+1);
        return ;
    }
    Pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(L<=m)update(L,R,c,lson);
    if(R>m)update(L,R,c,rson);
    Pushup(rt);
}
long long query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r)
    {
        return sum[rt];
    }
    Pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    long long ret=0;
    if(L<=m)ret+=query(L,R,lson);
    if(R>m)ret+=query(L,R,rson);
    return ret;
}
int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    build(1,n,1);
    while(t--)
    {
        char s[2];
        int a,b,c;
        scanf("%s",s);
        if(s[0]=='Q')
        {
            scanf("%d%d",&a,&b);
            printf("%lld\n",query(a,b,1,n,1));
        }
        else
        {
            scanf("%d%d%d",&a,&b,&c);
            update(a,b,c,1,n,1);
        }
    }
    return 0;
}
