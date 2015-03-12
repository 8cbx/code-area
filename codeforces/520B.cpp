#include<stdio.h>
#include<string.h>
int main()
{
    int n, m;
    int ans=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ans=0;
        if(n>m)
        {
            printf("%d\n",n-m);
            continue;
        }
        while(n!=m)
        {
            if(n>m)
            {
                n--;
                ans++;
            }
            else
            {
                if(m%2==1)
                {
                    m+=1;
                    ans++;
                }
                else
                {
                    m/=2;
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
