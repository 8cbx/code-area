#include<stdio.h>
#include<string.h>
int main()
{
    int x[150];
    for(int i=0; i<=100; i++)
    {
        x[i]=i*i;
    }
    int num,flag=0;
    while(scanf("%d",&num)!=EOF)
    {
        flag=0;
        for(int i=1; i<=100; i++)
        {
            for(int j=i; j<=100; j++)
            {
                for(int k=j; k<=100; k++)
                {
                    if(x[i]+x[j]+x[k]==num)
                    {
                        printf("%d %d %d\n",i,j,k);
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                {
                    break;
                }
            }
            if(flag==1)
            {
                break;
            }
        }
    }
    return 0;
}
