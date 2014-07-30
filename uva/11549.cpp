#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int wei[100];
int next(int n,int k)
{
    if(!k)
    {
        return 0;
    }
    long long k2=(long long)k*k;
    int l=0;
    while(k2>0)
    {
        wei[l++]=k2%10;
        k2/=10;
    }
    if(n>l)
    {
        n=l;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=ans*10+wei[--l];
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int ans=k;
        int k1=k,k2=k;
        do
        {
            k1=next(n,k1);
            k2=next(n,k2);
            if(k2>ans)
            {
                ans=k2;
            }
            k2=next(n,k2);
            if(k2>ans)
            {
                ans=k2;
            }
        }while(k1!=k2);
        printf("%d\n",ans);
    }
    return 0;
}
