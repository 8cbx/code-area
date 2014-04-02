#include<stdio.h>
#include<string.h>
int a[110];
int finde(int x)
{
    if(a[x]==0) return x;
    else return a[x]=finde(a[x]);
}
int main()
{
    int i,j,k,m,n,ans,aa,bb,ag,b,zero;
    int t[110];
    int temp;
    ans=0;
    zero=0;
    memset(a,0,sizeof(a));
    memset(t,0,sizeof(t));
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&temp);
        if(temp>0)
        {
            scanf("%d",&ag);
            t[ag]=1;
        }
        else
        {
            ans++;
            zero++;
        }

        if(temp>1)
        {
            for(j=2; j<=temp; j++)
            {
                scanf("%d",&b);
                t[b]=1;
                aa=finde(ag);
                //printf("--%d\n",aa);
                bb=finde(b);
                if(aa!=bb)
                {
                    a[bb]=aa;
                }
                //printf("j=%d\n",j);
            }
        }
       // printf("%d---\n",i);
    }
    //printf("%d\n",ans);
    for(i=1; i<=m; i++)
    {
        if(a[i]==0&&t[i]==1)
        {
            ans++;
            //
        }
    }
    if(zero==n)
    {
        ans++;
    }
    //printf("%d--\n",zero);
    printf("%d\n",ans-1);
    return 0;
}
