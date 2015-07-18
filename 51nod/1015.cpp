#include<stdio.h>
#include<string.h>
int main()
{
    int a;
    scanf("%d",&a);
    if(a<=153)
    {
        printf("153\n");
    }
    else if(a<=370)
    {
        printf("370\n");
    }
    else if(a<=371)
    {
        printf("371\n");
    }
    else if(a<=407)
    {
        printf("407\n");
    }
    else
    {
        printf("1634\n");
    }
    return 0;
}
