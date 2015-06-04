#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    int len;
    scanf("%s",s);
    len=strlen(s);
    if(len==1)
    {
        if(s[0]=='0'||s[0]=='8')
        {
            printf("YES\n%s\n",s);
        }
        else printf("NO\n");
        return 0;
    }
    if(len==2)
    {
        int ans=(s[0]-'0')*10+(s[1]-'0');
        if(ans%8==0)
        {
            printf("YES\n%s\n",s);
        }
        else
        {
            if(s[0]=='0'||s[1]=='0')
            {
                printf("YES\n0\n");
            }
            else if(s[0]=='8'||s[1]=='8')
            {
                printf("YES\n8\n");
            }
            else printf("NO\n");
        }
        return 0;
    }
    for(int i=0; i<len; i++)
    {
        if(s[i]=='0'||s[i]=='8')
        {
            printf("YES\n");
            printf("%c\n",s[i]);
            return 0;
        }
        for(int j=i+1; j<len; j++)
        {
            int anss=(s[i]-'0')*10+(s[j]-'0');
            if(anss%8==0)
            {
                printf("YES\n%c%c\n",s[i],s[j]);
                return 0;
            }
            for(int k=j+1; k<len; k++)
            {
                int ans=(s[i]-'0')*100+(s[j]-'0')*10+(s[k]-'0');
                if(ans%8==0)
                {
                    printf("YES\n");
                    printf("%c%c%c\n",s[i],s[j],s[k]);
                    return 0;
                }
            }
        }
    }
    printf("NO\n");
    return 0;
}
