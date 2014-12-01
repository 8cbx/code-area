#include<stdio.h>
#include<string.h>
#include<algorithm>
#define max(a,b) a>b?a:b
using namespace std;
int main()
{
    int a[1010];
    int i,j,k;
    int n;
    int l;
    while(scanf("%d%d",&n,&l)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int now=0;

        sort(a+1,a+1+n);
        int max_ans = a[1] * 2;
        for(i=1;i<=n;i++)
        {
            max_ans = max(max_ans, a[i] - now);
            now = a[i];
        }
        max_ans = max(max_ans, (l - a[n]) * 2);
        printf("%.10lf\n",(double)max_ans/2.0);
    }
    return 0;
}
