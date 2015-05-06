#include<stdio.h>
#include<string.h>
int match(char w[],char s[],int next[])
{
    int cnt=0;
    int slen=strlen(s);
    int wlen=strlen(w);
    int p=0,cur=0;
    while(cur<slen)
    {
        if(s[cur]==w[p])
        {
            cur++;
            p++;
        }
        else if(p>=0)
        {
            p=next[p];;
        }
        else
        {
            cur++;
            p=0;
        }
        if(p==wlen)
        {
            cnt++;
            p=next[p];
        }
    }
    return cnt;
}
int main()
{
    int loop;
    scanf("%d",&loop);
    while(loop--)
    {
        char w[10010],t[1000010];
        scanf("%s%s",w,t);
        int suf[10010];
        suf[0]=-1;
        suf[1]=0;
        int p=0;
        for(int cur=2;cur<=strlen(w);cur++)
        {
            while(p>=0&&w[p]!=w[cur-1])
            {
                p=suf[p];
            }
            suf[cur]=++p;
        }
        printf("%d\n",match(w,t,suf));
    }
    return 0;
}
