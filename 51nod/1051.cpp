#include<stdio.h>
#include<string.h>
int main()
{
    long long a[510][510];
    long long tmp;
    int n,m;
    scanf("%d%d",&m,&n);
    memset(a,0,sizeof(a));
    for(int i=1; i<=n; i++)
    {
        tmp=0LL;
        for(int j=1; j<=m; j++)
        {
            scanf("%lld",&a[i][j]);
            a[i][j]+=a[i-1][j];
        }
    }
    long long sum=-9999999999LL;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            tmp=0LL;
            for(int k=1; k<=m; k++)
            {
                if(tmp<=0)
                {
                    tmp=a[j][k]-a[i][k];
                }
                else tmp+=a[j][k]-a[i][k];
                if(tmp>sum)
                {
                    sum=tmp;
                }
                //printf("%lld %lld\n",tmp,sum);
            }
        }
    }
    printf("%lld\n",sum);
    return 0;
}
