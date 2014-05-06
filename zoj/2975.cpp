#include<stdio.h>
#include<string.h>
inline int know(char s)
{
    if(s=='B')return 1;
    if(s=='J')return 2;
    if(s=='H')return 3;
    if(s=='Y')return 4;
    return 5;
}
int main()
{
    char s[300][300],temp;
    int i,j,k,l;
    int ans[10];
    int t,n,m,sum;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            scanf("%d%d",&n,&m);
            scanf("%c",&temp);
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=m; j++)
                {
                    scanf("%c",&s[i][j]);
                }
                scanf("%c",&temp);
            }
            sum=0;
            for(i=1; i<n; i++)
            {
                for(j=i+1; j<=n; j++)
                {
                    memset(ans,0,sizeof(ans));
                    for(k=1; k<=m; k++)
                    {
                        if(s[i][k]==s[j][k])
                        {
                            ans[know(s[j][k])]++;
                        }
                    }
                    for(l=1; l<=5; l++)
                    {
                        sum+=ans[l]*(ans[l]-1)/2;
                    }
                }
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
