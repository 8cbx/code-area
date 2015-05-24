#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    int x[100010],h[100010];
    int ans;
    scanf("%d",&n);
    memset(h,0,sizeof(h));
    memset(x,0,sizeof(x));
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x[i],&h[i]);
    }
    ans=1;
    int left=x[1];
    for(int i=2;i<n;i++)
    {
        if(x[i]-h[i]>left)
        {
            ans++;
            left=x[i];
        }
        else if(x[i]+h[i]<x[i+1])
        {
            ans++;
            left=x[i]+h[i];
        }
        else
        {
            left=x[i];
        }
    }
    printf("%d\n",n>=2?(ans+1):(ans));
}
