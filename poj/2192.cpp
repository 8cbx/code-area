#include<stdio.h>
#include<string.h>
int main()
{
    int len1,len2;
    char s[210];
    char ss[210];
    char sss[410];
    int t;
    int cases=0;
    int c[210][210];
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        memset(c,0,sizeof(c));
        scanf("%s%s%s",s,ss,sss);
        len1=strlen(s);
        len2=strlen(ss);
        c[0][0]=1;
        if(s[0]==sss[0])c[1][0]=1;
        if(ss[0]==sss[0])c[0][1]=1;
        for(int i=0;i<=len1;i++)
        {
            for(int j=0;j<=len2;j++)
            {
                if(sss[i+j-1]==s[i-1]&&i>0)
                {
                    c[i][j]=c[i][j]||c[i-1][j];
                }
                if(sss[i+j-1]==ss[j-1]&&j>0)
                {
                    c[i][j]=c[i][j]||c[i][j-1];
                }
            }
        }
        printf("Data set %d: %s\n",cases,c[len1][len2]==1?"yes":"no");
    }
    return 0;
}
