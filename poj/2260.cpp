#include<stdio.h>
#include<string.h>
int main()
{
    int a,b[150],c[150];
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            return 0;
        }
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a);
                b[i]+=a;
                c[j]+=a;
            }
        }
        int flag=0,fl=0;
        for(int i=1;i<=n;i++)
        {
            if(b[i]%2==1)
            {
                if(flag==0)
                    flag=i;
                else flag=n+2;
            }
            if(c[i]%2==1)
            {
                if(fl==0)
                    fl=i;
                else fl=n+2;
            }
        }
        if(fl!=n+2&&flag!=n+2)
        {
            if(fl==0&&flag==0)
            {
                printf("OK\n");
            }
            else printf("Change bit (%d,%d)\n",flag,fl);
        }
        else printf("Corrupt\n");
    }
    return 0;
}
