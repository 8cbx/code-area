#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    char s;
    int coun;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%c",&s);
        while(n--)
        {
            scanf("%c",&s);
            coun=0;
            while(s!='\n')
            {
                if(s>='0'&&s<='9')
                {
                    coun++;
                }
                scanf("%c",&s);
            }
            printf("%d\n",coun);
        }
    }
    return 0;
}
