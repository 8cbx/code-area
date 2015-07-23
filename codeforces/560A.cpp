#include<stdio.h>
#include<string.h>
int main()
{
    int n,a;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a==1)
        {
            printf("-1\n");
            return 0;
        }
    }
    printf("1\n");
    return 0;
}
