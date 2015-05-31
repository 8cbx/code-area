#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    long long a[10010],m,k;
    long long n;
    int t,cases;
    scanf("%d",&t);
    cases=0;
    while(t--)
    {
        cases++;
        scanf("%I64d%I64d%I64d",&n,&m,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%I64d",&a[i]);
        }
        sort(a,a+n);
        int yes=0;
        for(int i=0;i<n&&a[i]<=m;i++)
        {
            int j=i;
            int l=i;
            int now=k;
            int flag=0;
            if(i!=n-1)
            {
                j++;
            }
            //printf("j: %d\n",j);
            while(j<n)
            {
                int ok=1;
                while(j<n&&a[j]-a[l]<=now)
                {
                    j++;
                    ok=0;
                }
                if(ok==1)
                {
                    flag=1;
                    break;
                }
                l=j-1;
                now--;
                if(now<0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                yes=1;
                break;
            }
        }
        printf("Case #%d:\n",cases);
        if(yes==1)
        {
            printf("why am I so diao?\n");
        }
        else
        {
            printf("madan!\n");
        }
    }
    return 0;
}
