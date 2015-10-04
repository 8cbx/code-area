#include<stdio.h>
#include<string.h>
int a[10000];
int vis[10000];
int main()
{
    int n;
    scanf("%d",&n);
    memset(vis,0,sizeof(vis));
    for(int i =1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    int now=0;
    int pos=1;
    int ans=0;
    int dir=0;
    while(now<n)
    {
        //printf("%d %d %d\n",now,pos,ans);
        if(a[pos]<=now&&vis[pos]==0)
        {
            now++;
            vis[pos]=1;
        }
        if(dir==0)
        {
            pos++;
            if(pos>n)
            {
                dir=1;
                pos-=2;
                if(now!=n)ans++;
            }
        }
        else if(dir==1)
        {
            pos--;
            if(pos<1)
            {
                dir=0;
                pos+=2;
                if(now!=n)ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
