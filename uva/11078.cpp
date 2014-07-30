#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j,maxx,ans;
    int a[100005];
    int n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        ans=a[1]-a[2];
        maxx=a[1];
        for(i=2; i<=n; i++)
        {
            if(ans<maxx-a[i])
            {
                ans=maxx-a[i];
            }
            if(a[i]>maxx)
            {
                maxx=a[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
