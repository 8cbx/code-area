#include<stdio.h>
#include<vector>
using namespace std;
vector<long long>a;
long long pow_mod(long long a,long long i,long long n)
{
    if(i==0)
    {
        return 1%n;
    }
    long long temp=pow_mod(a,i>>1,n);
    temp=temp*temp%n;
    if(i&1)
    {
        temp=(long long)temp*a%n;
    }
    return temp;
}
bool g_test(long long g,long long p)
{
    for(long long i=0;i<(int)a.size();++i)
    {
        if(pow_mod(g,(p-1)/a[i],p)==1)
            return 0;
    }
    return 1;
}
long long prim_root(long long p)
{
    long long tmp=p-1;
    for(long long i=2;i<tmp/i;i++)
    {
        if(tmp%i==0)
        {
            a.push_back(i);
            while(tmp%i==0)
            {
                tmp/=i;
            }
        }
    }
    if(tmp!=1)
    {
        a.push_back(tmp);
    }
    long long g=1;
    while(true)
    {
        if(g_test(g,p))
        {
            return g;
        }
        ++g;
    }
}
int main()
{
    long long p;
    scanf("%lld",&p);
    printf("%lld\n",prim_root(p));
}
