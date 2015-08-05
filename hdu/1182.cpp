#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int a[100];
    char s;
    memset(a,0,sizeof(a));
    while(scanf("%c",&s)!=EOF)
    {
        if(s!='\n')
        {
            if(s>='a'&&s<='z')
            {
                a[s-'a']++;
            }
            else
            {
                a[s-'A']++;
            }
        }
    }
    sort(a,a+26);
    int ans=0;
    for(int i=0;i<26;i++)
    {
        ans+=a[i]*(i+1);
    }
    printf("%d\n",ans);
    return 0;
}
