#include<stdio.h>
#include<string.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=111111;
int sum[maxn<<2];
int col[maxn<<2];
int Pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void Pushdown(int rt,int m)
{
    if(col[rt])
    {
        col[rt<<1]=col[rt<<1|1]=col[rt];
        sum[rt<<1]=(m-(m>>1))*col[rt];
        sum[rt<<1|1]=(m>>1)*col[rt];
        col[rt]=0;
    }
}
void build(int l,int r,int rt)
{
    col[rt]=0;
    sum[rt]=1;
    if(l==r)
    {
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
        col[rt]=c;
        sum[rt]=c*(r-l+1);
        return ;
    }
    Pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(L<=m)update(L,R,c,lson);
    if(R>m)update(L,R,c,rson);
    Pushup(rt);
}
int main()
{
    int a,b,n,i,t,l,r,c;

    while(scanf("%d",&t)!=EOF)
    {
        i=0;
        i++;
        while(t--)
        {
            scanf("%d",&n);
            build(1,n,1);
            scanf("%d",&b);
            while(b--)
            {
                scanf("%d%d%d",&l,&r,&c);
                update(l,r,c,1,n,1);
            }
            printf("Case %d: The total value of the hook is %d.\n",i,sum[1]);
            i++;
        }
    }
    return 0;
}
