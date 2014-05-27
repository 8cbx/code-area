#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    int i,j;
    int len,flag;
    char s[150];
    j=0;
    while(scanf("%d",&t)!=EOF)
    {
        j=0;
        j++;
        while(t--)
        {
            printf("Case #%d: ",j);
            j++;
            flag=0;
            scanf("%s",&s);
            len=strlen(s);
            if(len>=4)
            {
                for(i=0; i<=len-4; i++)
                {
                    if(s[i]=='d'&&s[i+1]=='e'&&s[i+2]=='s'&&s[i+3]=='u')
                    {
                        printf("nano");
                        flag=1;
                    }
                    printf("%c",s[i]);
                }
                for(i=len-3;i<len;i++)
                {
                    printf("%c",s[i]);
                }
            }
            else printf("%s",s);
            if(flag==0)
            {
                printf("nanodesu");
            }
            printf("\n");
        }
    }
    return 0;
}
