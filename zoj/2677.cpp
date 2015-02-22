#include<stdio.h>
#include<string.h>
#include<math.h>
#define INF 99999999
struct point
{
    double x,y;
}data[110];
double dp[110][110];

double minn(double a,double b)
{
    return a<b?a:b;
}
double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf",&data[i].x,&data[i].y);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=INF;
            }
        }
        dp[2][1]=dis(data[2],data[1]);
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                dp[i][j]=minn(dp[i][j],dp[i-1][j]+dis(data[i-1],data[i]));
                dp[i][i-1]=minn(dp[i][i-1],dp[i-1][j]+dis(data[i],data[j]));
            }
        }
        double ans=INF;
        for(int i=1;i<n;i++)
        {
            ans=minn(ans,dp[n][i]+dis(data[i],data[n]));
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
