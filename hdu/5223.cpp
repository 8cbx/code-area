#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#define MAXN 1005
#define LL long long
using namespace std;
int g[MAXN][MAXN];
int n, q;
int gcd(int a, int b)
{
    if(a % b == 0) return b;
    else
        return gcd(b, a % b);
}
struct Node
{
    int l, r, ans;
}input[MAXN];
LL a[MAXN];
void work(int l, int r, int gg)
{
    for(int i = l; i <= r; i++)
    {
        int temp = gcd(a[i], gg);
        a[i] = a[i] * (LL)gg;
        a[i] = a[i] / (LL)temp;
    }
}
bool judge(int num)
{
    int l = input[num].l, r = input[num].r, gg = input[num].ans;
    int rr = a[l];
    for(int i = l + 1; i <= r; i++)
    {
        rr = gcd(a[i], rr);
    }
    if(rr != gg) return false;
    else
        return true;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        bool flag = true;
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i++) a[i] = 1;
        for(int i = 0; i < q; i++)
        {
            scanf("%d%d%d", &input[i].l, &input[i].r, &input[i].ans);
            work(input[i].l, input[i].r, input[i].ans);
        }
        for(int i = 0; i < q; i++)
        {
            flag = judge(i);
            if(!flag) break;
        }
        if(flag)
        {
            for(int i = 1; i <= n; i++)
            {
                if(i != 1) printf(" ");
                printf("%I64d", a[i]);
            }
            puts("");
        }
        else
            puts("Stupid BrotherK!");
    }
    return 0;
}
