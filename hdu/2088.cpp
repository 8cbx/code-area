#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,n,i,s[55],k=0;
    while(scanf("%d",&n)!=EOF)
    {
        k++;
        a=0;
        if(n==0)
        {
            break;
        }
        if(k!=1)
        {
            printf("\n");
        }
        //printf("Set #%d\n",k);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&s[i]);
            a+=s[i];
        }
        a/=n;
        b=0;
        for(i=1;i<=n;i++)
        {
            if(s[i]>a)
            {
                b=b+s[i]-a;
            }
        }
        printf("%d\n",b);
    }
    return 0;
}
