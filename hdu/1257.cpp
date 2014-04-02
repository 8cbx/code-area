#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[100]={30000};
        int i=1;
        int m,j;
        while(n--)
        {
            scanf("%d",&m);
            for(j=0;j<=i;j++)
            {
                if(m<=a[j])
                {
                    a[j]=m;
                    break;
                }
            }
            if(j>i)
            {
                a[++i]=m;
            }
        }
        printf("%d\n",i);
    }
    return 0;
}
