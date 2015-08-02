#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int a,b[25],n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&a);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
        }
        sort(b+1,b+1+n,cmp);
        int now=(1<<(n))-1;
        int maxx=99999999;
        while(now>0)
        {
            int tmp=now;
            int to=1;
            int temp=a;
            int ans=0;
            //printf("%d\n",tmp);
            while(tmp>0)
            {
                //printf("%d\n",tmp);
                if(tmp%2==1)
                {
                    temp%=b[to];
                    ans++;
                }
                tmp/=2;
                to++;
            }
            if(ans<maxx&&temp==0)
            {
                maxx=ans;
            }
            now--;
        }
        if(maxx==99999999)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",maxx);
        }
    }
    return 0;
}
