#include<stdio.h>
#include<string.h>
int main()
{
    char s[15][15];
    char ch;
    int i,j,k,n,flag,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        printf("Case %d:\n",i);
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%s",s[j]);
        }
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(s[j][k]=='.')
                {
                    for(ch='A';ch<='Z';ch++)
                    {
                        flag=1;
                        if(k-1>=0&&ch==s[j][k-1])flag=0;
                        if(j-1>=0&&ch==s[j-1][k])flag=0;
                        if(k+1<n&&ch==s[j][k+1])flag=0;
                        if(j+1<n&&ch==s[j+1][k])flag=0;
                        if(flag==1)
                        {
                            s[j][k]=ch;
                            break;
                        }
                    }
                }
            }
        }
        for(j=0;j<n;j++)
        {
            printf("%s\n",s[j]);
        }
    }
    return 0;
}
