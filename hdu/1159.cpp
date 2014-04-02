#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int maxx(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    char a[502],b[502];
    int i,j,k;
    int f[502][502];
    while(scanf("%s%s",a,b)!=EOF)
    {
        int lena,lenb;
        lena=strlen(a);
        //printf("%d--\n",lena);
        lenb=strlen(b);
        //printf("%d---\n",lenb);
        memset(f,0,sizeof(f));
        for(i=1;i<=lena;i++)
        {
            for(j=1;j<=lenb;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    f[i][j]=f[i-1][j-1]+1;
                }
                else f[i][j]=maxx(f[i][j-1],f[i-1][j]);
            }
        }
        printf("%d\n",f[lena][lenb]);
    }
    return 0;
}
