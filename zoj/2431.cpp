#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    int a,b,c;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int flag=1;
        if(n<2)
        {
            printf("YES\n");
        }
        else if(n>2)
        {
            printf("NO\n");
        }
        else
        {
            flag=0;
            scanf("%d%d%d",&a,&b,&c);
            if(b*b-4*a*c>=0)
            {
                printf("NO\n");
            }
            else printf("YES\n");
        }
        if(flag==1)
        {
            for(int i=0;i<=n;i++)
            {
                scanf("%d",&a);
            }
        }
        if(t!=0)
        {
            printf("\n");
        }
    }
    return 0;
}
