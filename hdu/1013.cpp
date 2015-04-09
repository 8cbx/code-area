#include<stdio.h>
#include<stdlib.h>
int main()
{
    char s[1000];
    int i,j,m;
    while(scanf("%s",s)!=EOF)
    {
        if(s[0]=='0')
            break;
        for(i=m=0; s[i]; i++)
        {
            m+=s[i]-'0';
        }
        printf("%d\n",m%9==0?9:m%9);
    }
    return 0;
}
