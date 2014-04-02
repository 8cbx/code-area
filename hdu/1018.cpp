#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    int i,j;
    int a;
    double ans;
    scanf("%d",&n);
    while(n--)
    {
        ans=0;
        scanf("%d",&a);
        for(i=1;i<=a;i++)
        {
            ans+=log10(i);
        }
        ans++;
        printf("%d\n",(int)ans);
    }
    return 0;
}
