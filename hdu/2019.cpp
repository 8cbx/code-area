#include<stdio.h>
#include<string.h>
int main()
{
    int m,n;
    int i,flag;
    int num[150];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(m==0&&n==0)
        {
            break;
        }
        for(i=1; i<=n; i++)
        {
            scanf("%d",&num[i]);
        }
        flag=0;
        if(n>=2)
        {
            for(i=1; i<n; i++)
            {
                if(num[i]<=m&&num[i+1]>=m&&flag==0)
                {
                    printf("%d %d ",num[i],m);
                    flag=1;
                }
                else printf("%d ",num[i]);
            }
            if(flag==0)
            {
                printf("%d %d\n",num[n],m);
            }
            else printf("%d\n",num[n]);
        }
        else
        {
            if(num[1]>m)
            {
                printf("%d %d\n",m,num[1]);
            }
            else printf("%d %d\n",num[1],m);
        }
    }
    return 0;
}
