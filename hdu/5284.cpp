#include<stdio.h>
#include<string.h>
char s[3145750];
int main()
{
    int len;
    int t;
    int wb;
    int yb;
    scanf("%d",&t);
    while(t--)
    {
        int flag=0;
        scanf("%s",s);
        len=strlen(s);
        wb=len+1;
        yb=len+1;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='w'||(s[i]=='v'&&s[i+1]=='v'&&i<len-1))
            {
                wb=i;
                break;
            }
        }
        for(int i=wb;i<len;i++)
        {
            if(s[i]=='y')
            {
                yb=i;
                break;
            }
        }
        for(int i=yb;i<len;i++)
        {
            if(s[i]=='h')
            {
                printf("Yes\n");
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("No\n");
        }
    }
    return 0;
}
