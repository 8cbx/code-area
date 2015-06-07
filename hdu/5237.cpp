#include<stdio.h>
#include<string.h>
int wei[6]= {32,16,8,4,2,1};
char cha[]= {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};
char s[15000];
int num[65000];
char ss[15000];
void Base()
{
    int len=strlen(s);
    int lena=8*len;
    memset(num,0,sizeof(num));
    memset(ss,0,sizeof(ss));
    for(int i=0; i<len; i++)
    {
        int tmp=(int)s[i];
        int now=8*(i+1)-1;
        while(tmp>0)
        {
            num[now]=tmp%2;
            now--;
            tmp/=2;
        }
    }
    if(len%3==1)
    {
        lena+=4;
    }
    if(len%3==2)
    {
        lena+=2;
    }
    /*for(int i=0; i<lena; i++)
    {
        printf("%d",num[i]);
    }
    printf("\n");*/
    for(int i=0; i<lena; i+=6)
    {
        int ans=0;
        for(int j=0; j<6; j++)
        {
            ans+=num[i+j]*wei[j];
        }
        //printf("%d\n",ans);
        ss[i/6]=cha[ans];
    }
    if(len%3==1)
    {
        ss[lena/6]='=';
        ss[lena/6+1]='=';
        ss[lena/6+2]='\0';
    }
    if(len%3==2)
    {
        ss[lena/6]='=';
        ss[lena/6+1]='\0';
    }
    if(len%3==0)
    {
        ss[lena/6]='\0';
    }
    strcpy(s,ss);
}
int main()
{
    int k;
    int t;
    int cases=0;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        scanf("%d",&k);
        scanf("%s",s);
        for(int i=1; i<=k; i++)
        {
            Base();
        }
        printf("Case #%d: %s\n",cases,s);
    }
    return 0;
}
