#include<stdio.h>
int main()
{
    int a,b,c,d,i,j,k,t,l=0;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF)
    {
        if(a==-1&&b==-1&&c==-1&&d==-1)
            break;
        for(i=d+1; i<=(21252+d); i++)
        {
            if((i-a)%23==0)
            {
                break;
            }
        }
        for(; i<=(21252+d); i=i+23)
        {
            if((i-b)%28==0)
            {
                break;
            }
        }
        for(; i<=(21252+d); i=i+23*28)
        {
            if((i-c)%33==0)
            {
                break;
            }
        }
        l++;
        printf("Case %d: the next triple peak occurs in %d days.\n",l,i-d);
    }
    return 0;
}
