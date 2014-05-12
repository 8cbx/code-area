#include<stdio.h>
#include<math.h>
int prime(int a)
{
    int i;
    if(a==2)
    {
        return 0;
    }
    for(i=2; i<=sqrt(a); i++)
    {
        if(a%i==0)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int x,y,i,flag;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        if(x==0&&y==0)
        {
            break;
        }
        flag=0;
        for(i=x; i<=y; i++)
        {
            if(prime(i*i+i+41)==1)
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("OK\n");
        }
        else printf("Sorry\n");
    }
    return 0;
}
