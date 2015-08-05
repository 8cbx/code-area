#include <stdio.h>
long long fib[100] = {1, 1};
long long i2f(long long x, long long s[])
{
    long long w = 1;
    while(fib[w] <= x) ++w;
    --w;
    for(long long i = w; i > 0; --i)
    {
        if(x >= fib[i])
        {
            s[i - 1] = 1;
            x -= fib[i];
        }
        else
        {
            s[i - 1] = 0;
        }
    }
    return w;
}

long long f2i(long long w, long long s[])
{
    long long ret = 0;
    for(long long i = 0; i < w; ++i) if(s[i]) ret += fib[i + 1];
    return ret;
}

long long solve(long long x)
{
    long long w, s[100];
    w = i2f(x, s + 1);
    s[0] = 0;
    long long n = 1;
    while(!s[n]) ++n;
    if(n & 1)
    {
        return f2i(w + 1, s);
    }
    else
    {
        return f2i(w - 1, s + 2);
    }
}

void print(long long w, long long s[])
{
    for(long long i = w - 1; i >=0; --i) printf("%d",s[i]);
}

int main()
{
    for(long long i = 2; i < 100; ++i)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    long long a, b;
    long long t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld", &a, &b);
        if(solve(a) == b) puts("B");
        else puts("A");
    }
    return 0;
}
