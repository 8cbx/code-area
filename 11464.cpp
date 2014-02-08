#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
using namespace std;
int a[20][20];
int b[20][20];
int n;
int INF=100000000;
int maxn=20;
int check(int s)
{
    memset(b,0,sizeof(b));
    for(int c=0;c<=n;c++)
    {
        if(s&(1<<c))b[0][c]=1;
        else if(a[0][c]==1)return INF;
    }
    for(int r=1;r<n;r++)
    {
        for(int c=0;c<n;c++)
        {
            int sum=0;
            if(r>1)sum+=b[r-2][c];
            if(c>0)sum+=b[r-1][c-1];
            if(c<n-1)sum+=b[r-1][c+1];
            b[r][c]=sum%2;
            if(a[r][c]==1&&b[r][c]==0)return INF;
        }
    }
    int cnt=0;
    for(int r=0;r<n;r++)
    {
        for(int c=0;c<n;c++)
        {
            if(a[r][c]!=b[r][c])
                cnt++;
        }
    }
    return cnt;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        scanf("%d",&n);
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<n;c++)
            {
                scanf("%d",&a[r][c]);
            }
        }
        int ans=INF;
        for(int s=0;s<(1<<n);s++)
        {
            ans=min(ans,check(s));
        }
        if(ans==INF)ans=-1;
        printf("Case %d: %d\n",cases,ans);
    }
    return 0;
}
