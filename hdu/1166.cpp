#include<stdio.h>
#include<string.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=55555;
int sum[maxn<<2];
int Pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
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
void update(int p,int add,int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]+=add;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m)
    {
        update(p,add,lson);
    }
    else
    {
        update(p,add,rson);
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
int main()
{
    int n,i,j,t,l,r;
    char s[100];
    i=1;
    while(scanf("%d",&t)!=EOF)
    {
        i=1;
        while(t--)
        {
            scanf("%d",&n);
            build(1,n,1);
            printf("Case %d:\n",i);
            i++;
            while(scanf("%s",s)!=EOF)
            {
                if(s[0]=='E')
                {
                    break;
                }
                else if(s[0]=='Q')
                {
                    scanf("%d%d",&l,&r);
                    printf("%d\n",query(l,r,1,n,1));
                }
                else if(s[0]=='A')
                {
                    scanf("%d%d",&l,&r);
                    update(l,r,1,n,1);
                }
                else if(s[0]=='S')
                {
                    scanf("%d%d",&l,&r);
                    update(l,-r,1,n,1);
                }
            }
        }
    }
    return 0;
}
