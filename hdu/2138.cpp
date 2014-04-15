#include<stdio.h>
#include<string.h>
#include<math.h>
int che(int x)
{
    int i,j;
    for(i=2;i<=sqrt(x)+1;i++)
    {
        if(x%i==0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    int temp,ans,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        ans=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&temp);
            if(temp==1||temp==2)
            {
                ans++;
            }
            else if(che(temp)==1)
            {
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
