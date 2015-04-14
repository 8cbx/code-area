#include<stdio.h>
#include<string.h>
int main()
{
    int a[10010];
    int n;
    memset(a,0,sizeof(a));
    a[1]=1;
    for(int i=3;i<=10000;i++)
    {
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                a[i]=1;
                break;
            }
        }
    }
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            return 0;
        }
        int ans;
        int cnt;
        ans=0;
        for(int i=2;i<=n;i++)
        {
            cnt=0;
            if(a[i]==0)
            {
                for(int j=i;j<=n;j++)
                {
                    if(a[j]==0)
                    {
                        if(cnt<n)
                        {
                            cnt+=j;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                //printf("%d\n",cnt);
                if(cnt==n)
                {
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
