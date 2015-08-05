#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    int a[50010];
    int l,n;
    int maxx=0,minn=1999999999;
    scanf("%d%d",&n,&l);
//    double mid=l/2.0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        maxx=max(maxx,max(a[i],l-a[i]));
        minn=min(minn,(int)fabs(l-2*a[i]));
    }
    printf("%d %d\n",(l-minn)/2,maxx);
}
