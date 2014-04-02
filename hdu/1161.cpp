#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void strlwr(char a[1010])
{
    int len=strlen(a);
    for(int i=0;i<len;i++)
    {
        if(a[i]>='A'&&a[i]<='Z')
        {
            a[i]=a[i]-'A'+'a';
        }
    }
}
int main()
{
    char a[1010],temp;
    while(gets(a))
    {
        strlwr(a);
        puts(a);
    }
    return 0;
}
