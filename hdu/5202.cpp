#include<stdio.h>
#include<string.h>
int ok[1010];
int hui(char ss[])
{
    int len=strlen(ss);
    for(int i=0; i<len/2+1; i++)
    {
        if(ss[i]!=ss[len-1-i])
        {
            return 1;
        }
    }
    return 0;
}
int same(char s[],char ss[])
{
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        if(s[i]!='?')
        {
            if(s[i]!=ss[i])
            {
                return 0;
            }
        }
    }
    if(hui(ss)==1)
        return 1;
    else return 0;
}
int last(char ss[])
{
    int len=strlen(ss);
    for(int i=0; i<len; i++)
    {
        if(ok[i]==1)
        {
            if(ss[i]!='a')
            {
                return 0;
            }
        }
    }
    return 1;
}
int next(char *ss)
{
    int len=strlen(ss);
    len--;
    while(ok[len]!=1&&len>=0)
    {
        len--;
    }
    if(len==-1)
    {
        return 1;
    }
    ss[len]++;
    int flag=0;
    int jin=0;
    while(len>=0)
    {
        if(ok[len]==1)
        {
            if(ss[len]>'b')
            {
                if(len!=0)
                {
                    jin=1;
                }
                ss[len]='a';
                flag=1;
            }
            else if(jin==1)
            {
                ss[len]+=jin;
                if(ss[len]>'b')
                {
                    ss[len]='a';
                    jin=1;
                }
                else jin=0;
                flag=1;
            }
            else
            {
                if(flag==1)
                {
                    break;
                }
            }
        }
        len--;
    }
    if(jin==1)
    {
        return 1;
    }
    else return 0;
}
int main()
{
    char s[1010];
    char ss[1010];
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s",s);
        memset(ss,0,sizeof(ss));
        memset(ok,0,sizeof(ok));
        int coun=0;
        int len=strlen(s);
        for(int i=0; i<len; i++)
        {
            if(s[i]=='?')
            {
                ss[i]='a';
                ok[i]=1;
                coun++;
            }
            else
            {
                ss[i]=s[i];
            }
        }
        if(n==1)
        {
            printf("QwQ\n");
            continue;
        }
        int time=0;
        if(coun==0)
        {
            if(hui(s)==1)
            {
                printf("%s\n",s);
                continue;
            }
            else
            {
                printf("QwQ\n");
                continue;
            }
        }
        while(same(s,ss)!=1)
        {
            if(next(ss)==1)
            {
                break;
            }
            time++;
        }
        if(last(ss)==1&&time!=0)
        {
            printf("QwQ\n");
        }
        else printf("%s\n",ss);
    }
    return 0;
}
