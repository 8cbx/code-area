#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    int n;
    char s[15][65];
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%s",s[i]);
        }
        int len;
        char ans[65];
        len=0;
        int lens=strlen(s[0]);
        for(int i=0; i<lens; i++)
        {
            for(int j=i+2; j<lens; j++)
            {
                char com[65];
                strncpy(com,s[0]+i,j+1-i);
                com[j-i+1]='\0';
                int ok=1;
                for(int k=1; ok==1&&k<n; k++)
                {
                    if(strstr(s[k],com)==NULL)
                    {
                        ok=0;
                    }
                }
                if(ok==1&&(j-i+1>len||(j-i+1==len&&strcmp(ans,com)>0)))
                {
                    len=j-i+1;
                    strcpy(ans,com);
                }
            }
        }
        if(len<3)
        {
            printf("no significant commonalities\n");
        }
        else
        {
            printf("%s\n",ans);
        }
    }
    return 0;
}
