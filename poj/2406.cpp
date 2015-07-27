#include<stdio.h>
#include<string.h>
char s[1000010];
int main()
{
    int flag;
    //int len;
    while(scanf("%s",s)!=EOF)
    {
        int len=strlen(s);
        if(s[0]=='.')
        {
            break;
        }
        for(int i=1;i<=len;i++)
        {
            //printf("%d\n",i);
            if(len%i!=0)
            {
                continue;
            }
            for(int j=0;j<i;j++)
            {
                int now=j+i;
                flag=0;
                while(now<len)
                {
                    if(s[now]!=s[now-i])
                    {
                        flag=1;
                        break;
                    }
                    now+=i;
                }
                if(flag==1)
                {
                    break;
                }
            }
            if(flag==0)
            {
                printf("%d\n",len/i);
                break;
            }
        }
    }
    return 0;
}
