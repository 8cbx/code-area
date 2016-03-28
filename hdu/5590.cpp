#include<stdio.h>
#include<string.h>
int main()
{
    char s[150];
    char ss[150];
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            int n;
            scanf("%d",&n);
            scanf("%s",s+1);
            scanf("%s",ss+1);
            int flag=0;
            for(int i=1;i<=n;i++)
            {
                if(!((s[i]=='A'&&ss[i]=='U')||(s[i]=='T'&&ss[i]=='A')||
                  (s[i]=='C'&&ss[i]=='G')||(s[i]=='G'&&ss[i]=='C')))
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                printf("NO\n");
            }
            else
            {
                printf("YES\n");
            }
        }
    }
    return 0;
}

