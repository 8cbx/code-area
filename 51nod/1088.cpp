#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char s[100010];
char ss[100010<<1];
int p[100010<<1];
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        ss[(i<<1)+2]=s[i];
        ss[(i<<1)+3]='#';
    }
    ss[0]='?';
    ss[1]='#';
    ss[(len<<1)+2]='\0';
    int i,id,maxid=0,ans=1;
    len=2*len+2;
    for(i=0;i<len;i++)
    {
        if(maxid>i)
        {
            p[i]=min(p[2*id-i],maxid-i);
        }
        else p[i]=1;
        while(ss[i+p[i]]==ss[i-p[i]]&&i+p[i]<len&&i-p[i]>=0)
            p[i]++;
        if(p[i]+i>maxid)
        {
            maxid=p[i]+i;
            id=i;
        }
        if(ans<p[i])
        {
            ans=p[i];
        }
    }
    printf("%d\n",ans-1);
    return 0;
}
