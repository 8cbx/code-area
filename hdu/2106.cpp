#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,sum,n,i;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        while(n--)
        {
            scanf("%d(%d)",&a,&b);
            i=0;
            while(a>0)
            {
                c=a%10;
                a/=10;
                sum+=(int)pow(b,i)*c;
                i++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
