#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
#define abs(a) (a>0?a:(-a))
using namespace std;
int up[19]= {-2,-3,-5,-7,-11,-13,-17,-19,-23,-29,-31,-37,-41,-43,-47,-53,-59,-61,-67};
int main()
{
    int r;
    long long n;
    vector<int> howmany;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%d",&n,&r);
        howmany.clear();
        for(int i=0; abs(up[i])<=r; i++)
        {
            int tmp=howmany.size();
            for(int j=0; j<tmp; j++)
            {
                if(abs(up[i]*howmany[j])<=63)
                {
                    howmany.push_back(up[i]*howmany[j]);
                }
            }
            howmany.push_back(up[i]);
        }
        long long ans=n;
        while(1)
        {
            long long temp=ans;
            if(ans==1)
            {
                temp=0LL;
            }
            else
            {
                for(int i=0; i<(int)howmany.size(); i++)
                {
                    long long tmp=(long long)pow(ans+0.5,1.0/abs(howmany[i]))-1LL;
                    if(howmany[i]<0)
                    {
                        temp-=tmp;
                    }
                    else
                    {
                        temp+=tmp;
                    }
                }
                temp-=1;
            }
            //printf("%lld\n",temp);
            if(temp==n)
            {
                break;
            }
            ans+=n-temp;
            //printf("%lld\n",ans);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
