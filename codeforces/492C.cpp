#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct grade
{
    long long a,b;
} g[100010];
int cmp(grade a,grade b)
{
    return a.b<b.b;
}
int main()
{
    int i,j,k;
    long long  n,avg,sum,r;
    long long cost;
    cin>>n>>r>>avg;
    cost=0;
    sum=0;
    for(i=1; i<=n; i++)
    {
        scanf("%d%d",&g[i].a,&g[i].b);
        sum+=g[i].a;
    }
    if(sum>=n*avg)
    {
        printf("0\n");
        return 0;
    }
    sort(g+1,g+1+n,cmp);
    for(i=1; i<=n; i++)
    {
        if(avg*n-sum>r-g[i].a)
        {
            sum+=r-g[i].a;
            cost+=g[i].b*(r-g[i].a);
        }
        else
        {
            cost+=g[i].b*(avg*n-sum);
            break;
        }
    }
    cout<<cost<<endl;
    return 0;
}
