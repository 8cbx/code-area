#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("3.txt","w",stdout);
    int a[105];
    int sum,i;
    int n,summ;
    while(scanf("%d%d",&n,&summ)!=EOF)
    {
        sum=0;
        for(i=1; i<=n; i++)
        {
            a[i]=9;
            sum+=9;
        }
        if(n==1&&summ==0)
        {
            printf("0 0\n");
            continue;
        }
        if(summ==0||summ>9*n)
        {
            printf("-1 -1\n");
            continue;
        }
        /*if(sum<summ||n>summ)
        {
            printf("-1 -1\n");
            continue;
        }*/
        i=1;
        while(sum>summ)
        {
            if(i==1)
            {
                if(a[i]>1)
                {
                    a[i]--;
                    sum--;
                }
                else
                    i++;
            }
            else
            {
                if(a[i]>0)
                {
                    a[i]--;
                    sum--;
                }
                else
                    i++;
            }
        }
        for(i=1; i<=n; i++)
        {
            printf("%d",a[i]);
        }
        printf(" ");
        sum=0;
        for(i=1; i<=n; i++)
        {
            a[i]=9;
            sum+=9;
        }
        i=n;
        while(sum>summ)
        {
            if(a[i]>0)
            {
                a[i]--;
                sum--;
            }
            else
                i--;
        }
        for(i=1; i<=n; i++)
        {
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
