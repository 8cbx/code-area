#include<stdio.h>
#include<string.h>
long long c[1050];
long long a[50500];
long long b[50050];
long long d[50500];
long long ans[50500];
void make(int n)
{
    memset(c,0,sizeof(c));
    for(int i=1; i<=n+50; i++)
    {
        if(i>n)
        {
            d[i]=0;
        }
        else
        {
            d[i]=i;
            c[i/50]++;
        }
    }
}
int finds(int index,int n)
{
    int tmp=0;
    int now=0;
    for(int i=n; i>=0; i-=50)
    {
        tmp+=c[i/50];
        if(tmp>=index)
        {
            now=i/50;
            break;
        }
    }
    //printf("now: %d\n",now);
    for(int i=now*50; i<now*50+50; i++)
    {
        if(d[i]!=0)
        {
            if(tmp==index)
            {
                d[i]=0;
                c[i/50]--;
                return i;
            }
            else tmp--;
        }
    }
    return -1;
}
int main()
{
    int n;
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            scanf("%d",&n);
            memset(b,0,sizeof(b));
            for(int i=1; i<=n; i++)
            {
                scanf("%I64d",&a[i]);
            }
            b[1]=0;
            for(int i=2; i<=n; i++)
            {
                b[i]=a[i]-a[i-1];
            }
            make(n);
            for(int i=n; i>0; i--)
            {
                ans[i]=finds(b[i]+1,n);
            }
            for(int i=1; i<=n; i++)
            {
                if(i!=1)printf(" ");
                printf("%I64d",ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
