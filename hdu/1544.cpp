#include<stdio.h>
#include<string.h>
char s[5005];
int len,sum;
void exceed(int l,int a)
{
    int r=l;
    if(a==1)
    {
        l--;
        r++;
        while(s[l]==s[r]&&(l>=0&&r<len))
        {
            sum++;
            l--;
            r++;
        }
    }
    if(a==2)
    {
        l--;
        r+=2;
        while(s[l]==s[r]&&(l>=0&&r<len))
        {
            sum++;
            l--;
            r++;
        }
    }
}
int main()
{
    int i,j,k;
    while(scanf("%s",s)!=EOF)
    {
        sum=0;
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            sum++;
            exceed(i,1);
            if(s[i]==s[i+1])
            {
                sum++;
                exceed(i,2);
            }
        }
        printf("%d\n",sum);
    }
}
