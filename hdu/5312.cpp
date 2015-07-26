#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int a[100010];
int m;
void init()
{
    for(int i=1;;i++)
    {
        a[i]=3*i*(i-1)+1;
        if(a[i]>1000000000)
        {
            break;
        }
        m=i;
    }
}
int main()
{
    init();
    int t;
    int n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans;
        if(n%6==0)
        {
            ans=6;
        }
        else if(n%6==1)
        {
            if(*lower_bound(a+1,a+m+1,n)==n)
            {
                ans=1;
            }
            else ans=7;
        }
        else if(n%6==2)
        {
            int tmp=0;
            for(int i=1,j=m;i<=m&&a[i]<n;i++)
            {
                while(j>0&&a[i]+a[j]>n)
                {
                    j--;
                }
                if(j>0&&a[i]+a[j]==n)
                {
                    ans=2;
                    tmp=1;
                    break;
                }
            }
            if(!tmp)
            {
                ans=8;
            }
        }
        else
        {
            ans=n%6;
        }
        printf("%d\n",ans);
    }
    return 0;
}
