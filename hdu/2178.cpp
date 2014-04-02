#include<stdio.h>
#include<math.h>
int main()
{
    int a;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        printf("%d\n",(int)pow(2,a)-1);
    }
    return 0;
}
