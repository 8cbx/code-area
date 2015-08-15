#include<stdio.h>
#include<string.h>
struct data
{
    long long  h,w;
}a[60000];
int main()
{
    long long ans;
    long long n;
    scanf("%lld",&n);
    memset(a,0,sizeof(a));
    long long top=0;
    a[0].h=0;
    a[0].w=0;
    for(long long i=1; i<=n; i++)
    {
        long long tmp;
        scanf("%lld",&tmp);
        if(tmp>=a[top].h)
        {
            top++;
            a[top].h=tmp;
            a[top].w=1;
        }
        else
        {
            long long con=0;
            while(a[top].h>tmp&&top>0)
            {
                con+=a[top].w;
                if(ans<con*a[top].h)
                {
                    ans=(long long)con*(long long)a[top].h;
                }
                top--;
            }
            top++;
            a[top].h=tmp;
            a[top].w=con+1;
           // prlong long f("---%lld\n",ans);
        }
    }
    long long con=0;
    while(top>0)
    {
        con+=a[top].w;
        if(ans<con*a[top].h)
        {
            ans=(long long)con*(long long)a[top].h;
        }
        top--;
    }
    printf("%lld\n",ans);
}
