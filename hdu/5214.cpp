#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned int uint;

struct interval
{
  explicit interval(uint il = 0, uint ir = 0)
    :l(il), r(ir)
  {}
  interval(const interval& x)
    :l(x.l), r(x.r)
  {}
  uint l, r;
};

interval data[10000001];

int main()
{
  int T = 0;
  scanf("%d", &T);
  while(T--)
  {
    uint n = 0, lnow = 0, rnow = 0;
    uint a = 0, b = 0, c = 0, d = 0;
    //scanf("%u%u%u%u%u%u%u", &n, &lnow, &rnow, &a, &b, &c, &d);
    cin >> n >> lnow >> rnow >> a >> b >> c >> d;
    uint lmax = min(lnow, rnow), rmin = max(lnow, rnow);
    for(uint i = 0; i < n; ++i)
    {
      data[i].l = min(lnow, rnow);
      data[i].r = max(lnow, rnow);
      lmax = max(data[i].l, lmax);
      rmin = min(data[i].r, rmin);
      lnow = lnow * a + b;
      rnow = rnow * c + d;
    }
    bool isok = false;
    for(uint i = 0; i < n; ++i)
      if(data[i].l > rmin && data[i].r < lmax)
      {
        isok = true;
        break;
      }
    if(isok)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
