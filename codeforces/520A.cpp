#include<stdio.h>
#include<string.h>
int main()
{
    int ss[50];
    char s[120];
    int n;
    int flag;
    while(scanf("%d",&n)!=EOF)
    {
        flag=0;
        memset(ss,0,sizeof(ss));
        scanf("%s",s);
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]<='z'&&s[i-1]>='a')
            {
                s[i-1]-=('a'-'A');
            }
            ss[s[i-1]-'A'+1]=1;
        }
        for(int i=1;i<=26;i++)
        {
            if(ss[i]==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }
    return 0;
}
