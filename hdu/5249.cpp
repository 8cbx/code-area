#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=10010;
int sum[maxn<<2];
int a[10010];
void Pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
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
int query(int pos,int l,int r,int rt)
{
    if(l==r)
    {
        return a[l-1];
    }
    int m=(l+r)>>1;
    if(sum[rt<<1]>=pos)return query(pos,lson);
    else return query(pos-sum[rt<<1],rson);
}
int main()
{
    int n;
    int op[10010];
    int ora[10010];
    int time[10010];
    char s[10];
    int num,out,in;
    int cases,cnt;
    cases=0;
    while(scanf("%d",&n)!=EOF)
    {
        cases++;
        num=0;
        out=0;
        in=0;
        memset(op,0,sizeof(op));
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            //printf("%s---\n",s);
            if(strcmp(s,"in")==0)
            {
                op[i]=1;
                scanf("%d",&a[num]);
                ora[i]=a[num];
                time[num]=a[num];
                num++;
            }
            else if(strcmp(s,"out")==0)
            {
                op[i]=2;
            }
            else if(strcmp(s,"query")==0)
            {
                op[i]=3;
            }

        }
        sort(a,a+num);
        cnt = unique(a,a+num)-a;
        memset(sum, 0, sizeof(sum));
        printf("Case #%d:\n",cases);
        for(int i=0;i<n;i++)
        {
            //printf("%d\n",op[i]);
            if(op[i]==2)
            {
                int pos=lower_bound(a,a+cnt,time[out])- a + 1;
                //printf("%d\n", pos);
                out++;
                update(pos,-1,1,cnt,1);
            }
            else if(op[i]==1)
            {
                int pos=lower_bound(a,a+cnt,ora[i])-a+1;
                //printf("%d\n", pos);
                update(pos,1,1,cnt,1);
                in++;
            }
            else if(op[i]==3)
            {
                int pos = sum[1] / 2 + 1;
                printf("%d\n", query(pos, 1, cnt, 1));
            }
        }
    }
    return 0;
}
