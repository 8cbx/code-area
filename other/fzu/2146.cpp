#include<stdio.h>
#include<string.h>
int main()
{
    char s[10100];
    int n,len,i;
    while(scanf("%d",&n)!=EOF)
    {
        i=0;
        while(n--)
        {
            i++;
            printf("Case %d: ",i);
            scanf("%s",s);
            if(strlen(s)%2==0)
            {
                printf("Even\n");
            }
            else printf("Odd\n");
        }
    }
    return 0;
}
