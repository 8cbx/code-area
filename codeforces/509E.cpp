#include<stdio.h>
#include<string.h>
int main()
{
    int a[500010];
    char s[500010];
    int len;
    int i,x;
    while(scanf("%s",s)!=EOF)
    {
        memset(a,0,sizeof(a));
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]=='A'||s[i]=='I'||s[i]=='E'||s[i]=='O'||s[i]=='U'||s[i]=='Y')
            {
                x=1;
            }
            else
            {
                x=0;
            }
            a[i+1]=a[i]+x;
        }
        int l=0,r=len;
        long long ans=0;
        double anss=0.0;
        for(i=1;i<=len;i++)
        {
            ans+=a[r]-a[l];
            anss+=(double)ans/(double)i;
            l++;
            r--;
        }
        printf("%.10lf\n",anss);
    }
    return 0;
}
