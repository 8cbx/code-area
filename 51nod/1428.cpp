#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct data
{
    int a,b;
}time[10010];
int cmp(data a,data b)
{
    if(a.a==b.a)
    {
        return a.b<b.b;
    }
    return a.a<b.a;
}
int main()
{
    int a[10010];
    int n;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&time[i].a,&time[i].b);
    }
    sort(time+1,time+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        int k=1;
        //printf("++%d %d %d %d %d\n",k,i,a[k],time[i].a,time[i].b);
        while(a[k]>time[i].a)
        {
            k++;
        }
        a[k]=time[i].b;
        //printf("--%d %d %d %d %d\n",k,i,a[k],time[i].a,time[i].b);
    }
    int now=1;
    while(a[now]!=0)
    {
        now++;
    }
    printf("%d\n",now-1);
    return 0;
}
