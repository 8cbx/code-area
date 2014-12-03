#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n%2==1)
        {
            printf("black\n");
            continue;
        }
        else if(n%2==0)
        {
            printf("white\n1 2\n");
            continue;
        }
    }
    return 0;
}
