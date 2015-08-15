#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(int a,int b)
{
    int ans1=abs(a-b)*360;
    int ans2=12*60*60;
    int gcd=__gcd(ans1,ans2);
    ans1/=gcd;
    ans2/=gcd;
    if(ans1>ans2*180)ans1=360*ans2-ans1;
    if(ans2==1)
    {
        printf("%d ",ans1);
    }
    else
    {
        printf("%d/%d ",ans1,ans2);
    }
}
int main()
{
    int t;
    int a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d:%d:%d",&a,&b,&c);
        a%=12;
        a=(a*60+b)*60+c;
        b=12*(b*60+c);
        c=12*60*c;
        solve(a,b);
        solve(a,c);
        solve(b,c);
        printf("\n");
    }
    return 0;
}
