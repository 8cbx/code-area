#include<stdio.h>
#include<string.h>
long long a[500005];
int main()
{
    long long n,m,z,l;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%I64d%I64d%I64d%I64d",&n,&m,&z,&l);
        //printf("%d\n",a);
        for(int i=2; i<=n; i++)
        {
            a[i]=(a[i-1]*m+z)%l;
            //printf("%d\n",a[i]);
        }
        long long ans=a[1]*2LL;
        for(int i=2; i<=n; i++)
        {
            ans=ans^(2*a[i]);
            //printf("%d\n",ans);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
