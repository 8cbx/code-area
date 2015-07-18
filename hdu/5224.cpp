#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    int t;
    scanf("%d",&t);
    while(t--)
    //int ans=1999999999;
    //while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&n);
        int ans=1999999999;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0&&(i+i+n/i+n/i<ans))
            {
                ans=i+i+n/i+n/i;
            }
        }
        printf("%d\n",ans);
    }
}
