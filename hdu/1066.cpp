#include<stdio.h>
#include<string.h>
int main()
{
    int n,k;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        if(n%(k+1)==0)
        {
            printf("B\n");
        }
        else printf("A\n");
    }
    return 0;
}
