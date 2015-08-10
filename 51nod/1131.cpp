#include<stdio.h>
#include<string.h>
struct data
{
    long long a,b;
}muti[100000];
int main()
{
    long long a,b,x,y;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long ans=0;
        scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
        muti[0].a=a;
        muti[0].b=b;
        int con=0;
        for(int i=1;;i++)
        {
            muti[i].a=muti[i-1].a+a;
            muti[i].b=muti[i-1].b+b;
            con++;
            if(muti[i].a<=muti[i-1].b||muti[i].b>=y)
            {
                break;
            }
        }
        for(int i=0;i<=con;i++)
        {
            if(muti[i].b>=x)
            {
                if(muti[i].b<=y)
                {
                    if(muti[i].a<=x)
                    {
                        ans+=muti[i].b-x+1;
                    }
                    else
                    {
                        ans+=muti[i].b-muti[i].a+1;
                    }
                    x=muti[i].b;
                }
                else
                {
                    if(muti[i].a<=x)
                    {
                        ans+=y-x+1;
                    }
                    else
                    {
                        ans+=y-muti[i].a+1;
                    }
                    x=y;
                    break;
                }
            }
        }
        if(x<y)
        {
            ans+=y-x+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
