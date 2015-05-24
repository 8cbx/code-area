#include<stdio.h>
#include<string.h>
int main()
{
    char s1[100010];
    char s2[100010];
    int len;
    int coun=0;
    scanf("%s",s1);
    scanf("%s",s2);
    len=strlen(s1);
    for(int i=0;i<len;i++)
    {
        if(s1[i]!=s2[i])
            coun++;
    }
    if(coun%2==1)
    {
        printf("impossible\n");
    }
    else
    {
        coun/=2;
        for(int i=0;i<len;i++)
        {
            if(s1[i]!=s2[i])
            {
                if(coun>0)
                {
                    coun--;
                    printf("%c",s2[i]);
                }
                else printf("%c",s1[i]);
            }
            else printf("%c",s1[i]);
        }
        printf("\n");
    }
    return 0;
}
