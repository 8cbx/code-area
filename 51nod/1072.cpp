#include <stdio.h>
long long fib[100] = {1, 1};
int i2f(int x, int s[])
{
    int w = 1;
    while(fib[w] <= x) ++w;
    --w;
    for(int i = w; i > 0; --i)
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

int f2i(int w, int s[])
{
    int ret = 0;
    for(int i = 0; i < w; ++i) if(s[i]) ret += fib[i + 1];
    return ret;
}

int solve(int x)
{
    int w, s[100];
    w = i2f(x, s + 1);
    s[0] = 0;
    int n = 1;
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

void print(int w, int s[])
{
    for(int i = w - 1; i >=0; --i) printf("%d",s[i]);
}

int main()
{
    for(int i = 2; i < 100; ++i)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int a, b;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d", &a, &b);
        if(solve(a) == b) puts("B");
        else puts("A");
    }
    return 0;
}
