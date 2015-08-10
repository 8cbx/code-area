#include<stdio.h>
#include<string.h>
int main()
{
    int a[10010];
    int b[1010];
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int tmp;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            a[b[i]]++;
        }
        tmp=0;
        for(int i=1;i<=n;i++)
        {
            if(a[b[i]]>n-a[b[i]])
            {
                printf("%d\n",b[i]);
                tmp=1;
                break;
            }
        }
        if(tmp==0)
        {
            printf("-1\n");
        }
    }
    return 0;
}
