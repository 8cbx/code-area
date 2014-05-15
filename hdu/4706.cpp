#include<stdio.h>
#include<string.h>
int a[100][100];
int print(int j,int start)
{
    memset(a,0,sizeof(a));
    for(int i=1;i<=3*j-2;i++)
    {
        if(i>j&&i<=j+j-2)
        {
            a[j-(i-j)][i-j+1]=start;

            start++;
            if(start>26)
            {
                start-=26;
            }
        }
        else if(i>j+j-2)
        {
            a[i-(2*j-1)+1][j]=start;
            //printf("%d %d\n",i-(2*j-1)+1,j-1);
            start++;
            if(start>26)
            {
                start-=26;
            }
        }
        else
        {
            a[i][1]=start;
            start++;
            if(start>26)
            {
                start-=26;
            }
        }
    }
    for(int i=1;i<=j;i++)
    {
        for(int k=1;k<=j;k++)
        {
            if(a[i][k]!=0)
            {
                printf("%c",a[i][k]+'A'-1);
            }
            else printf(" ");
        }
        printf("\n");
    }
    return start;
}
int main()
{
    int j,start;
    start=1;
    for(j=3;j<=10;j++)
    {
        start=print(j,start);
    }
    return 0;
}
