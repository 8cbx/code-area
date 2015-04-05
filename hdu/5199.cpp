#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
map<int,int>sum;
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        sum.clear();
        int a;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            sum[a]++;
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&a);
            printf("%d\n",sum[a]);
            sum[a]=0;
        }
    }
    return 0;
}
