#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
int a[1000];
int vis[45100];
vector<int> num;
void init()
{
    memset(vis,0,sizeof(vis));
    vis[0]=vis[1]=1;
    num.clear();
    for(int i=2; i*i<=2*1e9; i++)
    {
        //printf("%d\n",i);
        if(vis[i]==0)
        {
            num.push_back(i);
            for(int j=i+i; (long long)j*(long long)j<=2LL*1e9; j+=i)
            {
                //printf("--%d\n",j);
                vis[j]=1;
                //printf("--%d\n",j);
            }
        }
    }
}
int main()
{
    int t;
    int n;
    init();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        int siz=num.size();
        int minn=2*1e9+1,minnn=2*1e9+1;
        for(int i=1; i<=n; i++)
        {
            int tmp=a[i];
            for(int j=0; j<siz&&num[j]*num[j]<=a[i]; j++)
            {
                while(tmp%num[j]==0)
                {
                    tmp/=num[j];
                    if(num[j]<minn)
                    {
                        minnn=minn;
                        minn=num[j];
                    }
                    else
                    {
                        if(num[j]==minn)
                        {
                            minnn=minn;
                        }
                        else if(num[j]<minnn)
                        {
                            minnn=num[j];
                        }
                    }
                }
            }
            if(tmp>1)
            {
                if(tmp<minn)
                {
                    minnn=minn;
                    minn=tmp;
                }
                else if(tmp==minn)
                {
                    minnn=minn;
                }
                else if(tmp<minnn)
                {
                    minnn=tmp;
                }
            }
        }
        if(minnn==2*1e9+1)
        {
            printf("-1\n");
        }
        else
        {
            printf("%lld\n",(long long)minn*(long long)minnn);
        }
    }
    return 0;
}
