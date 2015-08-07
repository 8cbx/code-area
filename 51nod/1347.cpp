#include<stdio.h>
#include<string.h>
char s[2000010];
int main()
{
    int maxx=0;
    scanf("%s",s);
    int len=strlen(s);
    if(len%2==1)
    {
        printf("NO\n");
        return 0;
    }
    for(int i=0;i<len;i++)
    {
        s[i+len]=s[i];
    }
    s[len*2]='\0';
    int tmp=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]==s[i+len/2])
        {
            tmp++;
            if(tmp>maxx)
            {
                maxx=tmp;
            }
        }
        else
        {
            tmp=0;
        }
    }
    if(maxx>=len/2)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
