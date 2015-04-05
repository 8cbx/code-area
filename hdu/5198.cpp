#include<stdio.h>
#include<string.h>
#include<iostream>
#include<map>
using namespace std;
map<char,int> a;
int main()
{
    int len;
    char s[15];
    while(scanf("%s",s)!=EOF)
    {
        len=strlen(s);
        a.clear();
        if(len%3!=0)
        {
            printf("NO\n");
            continue;
        }
        int time=len/3;
        for(int i=0;i<len;i++)
        {
            a[s[i]]++;
        }
        int flag=0;
        for(int i=0;i<len;i+=time)
        {
            for(int j=1;j<time;j++)
            {
                if(s[i+j]!=s[i+j-1])
                {
                    flag=1;
                }
            }
        }
        for(int i=0;i<len;i+=time)
        {
            if(a[s[i]]!=time)
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
