#include<stdio.h>
#include<string.h>
#define minn(a,b) (a<b?a:b)
int min(int a,int b,int c)
{
    return minn(minn(a,b),c);
}
int main()
{
    int n,m,p,q;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&m,&p,&q);
        int ans1=n*p;
        int ans2=n/m*q+n%m*p;
        if(n%m!=0)
        {
            int ans3=(n/m+1)*q;
            printf("%d\n",min(ans1,ans2,ans3));
        }
        else
        {
            printf("%d\n",minn(ans1,ans2));
        }
    }
    return 0;
}
