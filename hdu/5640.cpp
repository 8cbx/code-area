#include<stdio.h>
#include<string.h>
int cacl(int a,int b)
{
    if(a==b)
    {
        return 1;
    }
    else
    {
        int tmp=a-b;
        if(tmp>b)
        {
            return cacl(tmp,b)+1;
        }
        else
        {
            return cacl(b,tmp)+1;
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    int a,b;
    while(t--)
    {
        scanf("%d%d",&a,&b);
        if(a<b)
        {
            int tmp;
            tmp=a;
            a=b;
            b=tmp;
        }
        printf("%d\n",cacl(a,b));
    }
    return 0;
}
