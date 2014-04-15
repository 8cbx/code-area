#include<stdio.h>
#include<string.h>
int sum[200010];
int pre[200010];
int n,m;
int findd(int x)
{
    if(x!=pre[x])
    {
        int f=pre[x];
        pre[x]=findd(pre[x]);
        sum[x]+=sum[f];
    }
    return pre[x];
}
int main()
{
    int i,j,k,l,r,s,ans,la,ra;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<=n;i++)
        {
            pre[i]=i;
        }
        memset(sum,0,sizeof(sum));
        ans=0;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&l,&r,&s);
            l--;
            la=findd(l);
            ra=findd(r);
            if(la==ra)
            {
                if(sum[l]-sum[r]!=s)
                {
                    ans++;
                }
            }
            else
            {
                pre[la]=ra;
                sum[la]=sum[r]-sum[l]+s;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
