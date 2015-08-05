#include<stdio.h>
#include<string.h>
int stac[100010];
int main()
{
    int n,top=0;
    int a,b;
    int cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        if(b==1)
        {
            stac[top]=a;
            top++;
        }
        else if(top==0&&b==0)
        {
            cnt++;
        }
        else
        {
            while(a>stac[top-1])
            {
                top--;
                if(top==0)
                {
                    cnt++;
                    break;
                }
            }
        }
    }
    while(top!=0)
    {
        cnt++;
        top--;
    }
    printf("%d\n",cnt);
    return 0;
}
