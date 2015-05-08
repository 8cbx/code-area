#include<stdio.h>
#include<string.h>
int main()
{
    char s[150];
    int a[30];
    int b[30];
    int n,ans=0,len;
    scanf("%d%s",&n,s);
    len=strlen(s);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=0;i<len;i++)
    {
        int k=s[i]-'a';
        if(a[k]==0)
        {
            a[k]=1;
            ans++;
        }
    }
    if(ans<n)
    {
        printf("NO\n");
        return 0;
    }
    else
    {
        printf("YES\n");
        ans=1;
        for(int i=0;i<len;i++)
        {
            int k=s[i]-'a';
            if(b[k]==0)
            {
                if(i!=0&&ans<n)
                {
                    printf("\n%c",s[i]);
                    ans++;
                }
                else printf("%c",s[i]);
                b[k]=1;
            }
            else printf("%c",s[i]);
        }
    }
    return 0;
}
