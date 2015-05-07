#include<stdio.h>
#include<string.h>
#define maxx(a,b,c) a>b?(a>c?a:c):(b>c?b:c)
int main()
{
    int arr[5][5]={0,-3,-4,-2,-1,-3,5,-1,-2,-1,-4,-1,5,-3,-2,-2,-2,-3,5,-2,-1,-1,-2,-2,5};
    int len1;
    int len2;
    char s[150];
    char ss[150];
    int a[150];
    int b[150];
    int t;
    int f[150][150];
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(f,0,sizeof(f));
        scanf("%d%s",&len1,s);
        scanf("%d%s",&len2,ss);
        for(int i=0;i<len1;i++)
        {
            if(s[i]=='A')
                a[i]=1;
            else if(s[i]=='C')
                a[i]=2;
            else if(s[i]=='G')
                a[i]=3;
            else if(s[i]=='T')
                a[i]=4;
        }
        for(int i=0;i<len2;i++)
        {
            if(ss[i]=='A')
                b[i]=1;
            else if(ss[i]=='C')
                b[i]=2;
            else if(ss[i]=='G')
                b[i]=3;
            else if(ss[i]=='T')
                b[i]=4;
        }
        for(int i=0;i<=len1+1;i++)
        {
            for(int j=0;j<=len2+1;j++)
            {
                if(i>0&&j>0)f[i][j]=maxx(f[i-1][j]+arr[0][a[i-1]],f[i][j-1]+arr[0][b[j-1]],f[i-1][j-1]+arr[a[i-1]][b[j-1]]);
                else
                {
                    if(i>0)
                    {
                        f[i][j]=f[i-1][j]+arr[0][a[i-1]];
                    }
                    else if(j>0)
                    {
                        f[i][j]=f[i][j-1]+arr[0][b[j-1]];
                    }
                }
            }
        }
        printf("%d\n",maxx(f[len1][len2],f[len1+1][len2],f[len1][len2+1]));
    }
    return 0;
}
