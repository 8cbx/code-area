#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,k;
    while(scanf("%d%d%d",&a,&b,&k)!=EOF)
    {
        if(a==0&&b==0)
        {
            break;
        }
        int ans=a+b;
        int flag=1,now=0;
        while(now<k)
        {
            now++;
            if(a%10!=b%10)
            {
                flag=0;
                break;
            }
            a/=10;
            b/=10;
        }
        if(flag==0)
        {
            printf("%d\n",ans);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
