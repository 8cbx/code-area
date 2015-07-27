#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
char s[5010];
char ss[5010];
int maxlen[2][5010];
int main()
{
    int n,i,j;
    while(scanf("%s",s+1)!=EOF)
    {
        s[0]='s';
        n=strlen(s)-1;
        for(int i=1;i<=n;i++)
        {
            ss[i]=s[n-i+1];
        }
        memset(maxlen,0,sizeof(maxlen));
        int e=0;
        for(int i=1;i<=n;i++)
        {
            e=1-e;
            for(int j=0;j<=n;j++)
            {
                if(s[i]==ss[j])
                {
                    maxlen[e][j]=maxlen[1-e][j-1]+1;
                }
                else
                {
                    int len1=maxlen[e][j-1];
                    int len2=maxlen[1-e][j];
                    if(len1>len2)maxlen[e][j]=len1;
                    else maxlen[e][j]=len2;
                }
            }
        }
        printf("%d\n",n-maxlen[e][n]);
    }
    return 0;
}
