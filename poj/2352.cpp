#include<stdio.h>
#include<string.h>
int c[32010],lv[32010],n;
int lowbit(int x)
{
    return x&(-x);
}
int sum(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=c[x];
        x-=lowbit(x);
    }
    return ret;
}
void add(int x)
{
    while(x <= 32010)
    {
        c[x]++;
        x+=lowbit(x);
    }
}
int main()
{
    int n,x,y,i;
    while(scanf("%d",&n)!=EOF)
    {
        memset(lv,0,sizeof(lv));
        memset(c,0,sizeof(c));
        for(i=1; i<=n; i++)
        {
            scanf("%d%d",&x,&y);
            x++;
            lv[sum(x)]++;
            add(x);
        }
        for(i=0; i<n; i++)
        {
            printf("%d\n",lv[i]);
        }
    }
    return 0;
}
