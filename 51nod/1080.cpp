#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    int flag=0;
    for(int i=0;i<=sqrt(n);i++)
    {
        int j=sqrt(n-i*i);
        if(j<i)
        {
            break;
        }
        if(j*j+i*i==n)
        {
            flag=1;
            printf("%d %d\n",i,j);
        }
        if(j==i)
        {
            break;
        }
    }
    if(flag==0)
    {
        printf("No Solution\n");
    }
    return 0;
}
