#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int a[50010];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
