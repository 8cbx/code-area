#include<stdio.h>
#include<string.h>
int main()
{
    char s[105];
    int t;
    char ss[100];
    char sss[100];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int len=strlen(s);
        int len2=len/2;
        for(int i=0;i<len;i+=2)
        {
            ss[i/2]=s[i];
            sss[len2-i/2-1]=s[i+1];
        }
        ss[len2]='\0';
        sss[len2]='\0';
        printf("%s\n%s\n",ss,sss);
    }
    return 0;
}
