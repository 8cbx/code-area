#include<stdio.h>
#include<string.h>
int main()
{
    char s;
    int flag;
    flag=0;
    while(scanf("%c",&s)!=EOF)
    {
        if(s=='"')
        {
            if(flag==0)
            {
                printf("``");
                flag=1;
            }
            else
            {
                printf("''");
                flag=0;
            }
        }
        else printf("%c",s);
    }
    return 0;
}
