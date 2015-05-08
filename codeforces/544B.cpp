#include<stdio.h>
#include<string.h>
int main()
{
    int n,k;
    int ans;
    ans=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        if(i%2==0)
        {
            ans+=n/2;
        }
        else ans+=n-(n/2);
    }
    //printf("%d\n",ans);
    if(ans>=k)
    {
        printf("YES\n");
        int tim=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(tim<k)
                {
                    if((i+j)%2==0)
                    {
                        printf("L");
                        tim++;
                    }
                    else printf("S");
                }
                else printf("S");
            }
            printf("\n");
        }
    }
    else printf("NO\n");
    return 0;
}
