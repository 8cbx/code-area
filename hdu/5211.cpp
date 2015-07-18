#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct point
{
    int a,b;
}point[10010];
int vis[10010];
int id[10010];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        long long ans=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&point[i].a);
            if(point[i].a==1)
            {
                if(i!=n)
                {
                    ans+=i+1;
                }
            }
            vis[point[i].a]=1;
            id[point[i].a]=i;
        }
        for(int i=2;i<=n;i++)
        {
            int now=point[i].a;
            //printf("%d\n",now);
            for(int j=2;j*j<=now;j++)
            {
                if(now%j==0)
                {
                    //printf("%d %d\n",i,j);
                    if(vis[j]==1&&id[j]<i)
                    {
                        ans+=i;
                        vis[j]=2;
                    }
                    if(vis[now/j]==1&&id[now/j]<i)
                    {
                        ans+=i;
                        vis[now/j]=2;
                    }
                }
            }
            /*for(int j=1;j<=n;j++)
            {
                printf("%d ",vis[j]);
            }
            printf("\n");*/
        }
        printf("%lld\n",ans);
    }
    return 0;
}
