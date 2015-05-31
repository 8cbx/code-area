#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<climits>
#include<map>
using namespace std;
map<int ,int> ma;
int main()
{
    int num[10010];
    int kk[1010];
    int k;
    int n;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&num[i]);
    }
    printf("Case #1:\n");
    memset(kk,0,sizeof(kk));
    for(int j=1; j<=n; j++)
    {
        int maxx=num[j];
        int minn=num[j];
        ma.clear();
        for(int now=0; now<1000; now++)
        {
            //printf("%d\n",(int)ma.count(num[j+now]));
            if(j+now>n)
            {
                break;
            }
            if(ma.count(num[j+now])!=0)
            {
                break;
            }
            ma[num[j+now]]=1;
            if(num[j+now]>maxx)
            {
                maxx=num[j+now];
            }
            if(num[j+now]<minn)
            {
                minn=num[j+now];
            }
            if(maxx-minn==now)
            {
                kk[now+1]++;
            }
        }
    }
    for(int i=1; i<=k; i++)
    {
        int todo;
        scanf("%d",&todo);
        printf("%d\n",kk[todo]);
    }
    return 0;
}
