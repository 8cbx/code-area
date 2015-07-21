#include<stdio.h>
#include<string.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=100010;
int sum1[maxn<<2],sum2[maxn<<2];
int a[100010];
int cur;
void Pushup2(int rt)
{
    sum2[rt]=sum2[rt<<1]>sum2[rt<<1|1]?sum2[rt<<1]:sum2[rt<<1|1];
}
void Pushup1(int rt)
{
    sum1[rt]=sum1[rt<<1]<sum1[rt<<1|1]?sum1[rt<<1]:sum1[rt<<1|1];
}
void build1(int l,int r,int rt)
{
    if(l==r)
    {
        sum1[rt]=a[cur];
        cur++;
        return;
    }
    int m=(l+r)>>1;
    build1(lson);
    build1(rson);
    Pushup1(rt);
}
void build2(int l,int r,int rt)
{
    if(l==r)
    {
        sum2[rt]=a[cur];
        cur++;
        return;
    }
    int m=(l+r)>>1;
    build2(lson);
    build2(rson);
    Pushup2(rt);
}
int query1(int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r)
    {
        return sum1[rt];
    }
    int m=(l+r)>>1;
    int ret=1999999999;
    if(L<=m)
    {
        int now=query1(L,R,lson);
        ret=ret<now?ret:now;
    }
    if(R>m)
    {
        int now=query1(L,R,rson);
        ret=ret<now?ret:now;
    }
    return ret;
}
int query2(int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r)
    {
        return sum2[rt];
    }
    int m=(l+r)>>1;
    int ret=-1;
    if(L<=m)
    {
        int now=query2(L,R,lson);
        ret=ret>now?ret:now;
    }
    if(R>m)
    {
        int now=query2(L,R,rson);
        ret=ret>now?ret:now;
    }
    return ret;
}
int main()
{
    int t;
    int min,max;
    int n,k;
    long long ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        memset(sum1,0,sizeof(sum1));
        memset(sum2,0,sizeof(sum2));
        n++;
        a[n]=2147483647;
        cur=1;
        build1(1,n,1);
        cur=1;
        build2(1,n,1);
        ans=0LL;
        min=a[1];
        max=a[1];
        int begi=1;
        int now=2;
        while(begi!=n)
        {
            if(a[now]<min)
            {
                min=a[now];
            }
            if(a[now]>max)
            {
                max=a[now];
            }
            if(max-min>=k)
            {
                ans+=(now-begi);
                //printf("--%lld %d %d %d\n",ans,(now-begi),begi,now);
                begi++;
                now--;
                max=query2(begi,now,1,n,1);
                min=query1(begi,now,1,n,1);
            }
            now++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
