#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long inv[200001],fac[200001],rfac[200001];
long long dp[200001];
int M=1e9+7;
void init()
{
    inv[0] = inv[1] = fac[0] = fac[1] = rfac[0] = rfac[1] = 1LL;
    for(int i = 2; i < 200001; ++i)
    {
        inv[i] = (M - M / i) * inv[M % i] % M;
        fac[i] = fac[i - 1] * i % M;
        rfac[i] = rfac[i - 1] * inv[i] % M;
    }
}
long long C (int x, int y)
{
    return (fac[x] * rfac[y] % M) * rfac[x - y] % M;
}
struct data
{
    int x,y;
}point[200001];
int cmp(data a,data b)
{
    if(a.x==b.x)
    {
        return a.y<b.y;
    }
    return a.x<b.x;
}
int main()
{
    int h,w,n;
    init();
    scanf("%d%d%d",&h,&w,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&point[i].x,&point[i].y);
    }
    n++;
    point[n].x=h;
    point[n].y=w;
    sort(point+1,point+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        int a,b;
        a=point[i].x-1;
        b=point[i].y-1;
        dp[i]=C(a+b,a);
        long long ans=0;
        for(int j=1;j<i;j++)
        {
            if(point[i].x>=point[j].x&&point[i].y>=point[j].y)
            {
                a=point[i].x-point[j].x;
                b=point[i].y-point[j].y;
                long long tmp=C(a+b,a);
                //printf("***%lld\n",tmp);
                tmp=dp[j]*tmp%M;
                ans+=tmp;
                ans%=M;
            }
            //printf("!!%lld\n",ans);
        }
        //printf("--%lld %lld\n",dp[i],ans);
        dp[i]-=ans;
        dp[i]+=M;
        dp[i]%=M;
    }
    printf("%lld\n",dp[n]);
    return 0;
}
