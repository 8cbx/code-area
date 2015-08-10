#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
const int S = 8; //随机算法判定次数,一般8~10就够了
// 计算ret = (a*b)%c
long long mult_mod(long long a,long long b,long long c)
{
    a %= c;
    b %= c;
    long long ret = 0;
    long long tmp = a;
    while(b)
    {
        if(b & 1)
        {
            ret += tmp;
            if(ret > c)ret -= c;//直接取模慢很多
        }
        tmp <<= 1;
        if(tmp > c)tmp -= c;
        b >>= 1;
    }
    return ret;
}
// 计算 ret = (a^n)%mod
long long pow_mod(long long a,long long n,long long mod)
{
    long long ret = 1;
    long long temp = a%mod;
    while(n)
    {
        if(n & 1)ret = mult_mod(ret,temp,mod);
        temp = mult_mod(temp,temp,mod);
        n >>= 1;
    }
    return ret;
}
// 通过 a^(n-1)=1(mod n)来判断n是不是素数
// n-1 = x*2^t 中间使用二次判断
// 是合数返回true, 不一定是合数返回false
bool check(long long a,long long n,long long x,long long t)
{
    long long ret = pow_mod(a,x,n);
    long long last = ret;
    for(int i = 1; i <= t; i++)
    {
        ret = mult_mod(ret,ret,n);
        if(ret == 1 && last != 1 && last != n-1)return true;//合数
        last = ret;
    }
    if(ret != 1)return true;
    else return false;
}
//**************************************************
// Miller_Rabin算法
// 是素数返回true,(可能是伪素数)
// 不是素数返回false
//**************************************************
bool Miller_Rabin(long long n)
{
    if( n < 2)return false;
    if( n == 2)return true;
    if( (n&1) == 0)return false;//偶数
    long long x = n - 1;
    long long t = 0;
    while( (x&1)==0 )
    {
        x >>= 1;
        t++;
    }
    srand(time(NULL));/* *************** */
    for(int i = 0; i < S; i++)
    {
        long long a = rand()%(n-1) + 1;
        if( check(a,n,x,t) )
            return false;
    }
    return true;
}
int main()
{
    int T;
    long long n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        if(Miller_Rabin(n))printf("Yes\n");
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
