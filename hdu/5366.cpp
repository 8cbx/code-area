#include<stdio.h>
#include<string.h>
long long ans[65];
void init()
{
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=61;i++)
    {
        ans[i]=1;
    }
    ans[0]=0;
    ans[1]=1;
    ans[2]=1;
    for(int i=3;i<=61;i++)
    {
        for(int j=i-3;j>=0;j--)
        {
            ans[i]+=ans[j];
        }
    }
}
int main()
{
    int n;
    init();
    while(scanf("%d",&n)!=EOF)
    {
        long long anss=0;
        for(int i=1;i<=n;i++)
        {
            anss+=ans[i];
        }
        printf("%I64d\n",anss);
    }
    return 0;
}
