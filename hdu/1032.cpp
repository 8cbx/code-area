#include<string.h>
#include<stdio.h>
int solve(int a,int b)
{
    if(a==1)return b;
    else a=a%2==0?a/2:a*3+1;
    return solve(a,b+1);
}
int main()
{
    int i,j,maxx,k,ii,jj;
    while(scanf("%d%d",&i,&j)!=EOF)
    {
        maxx=0;
        ii=i;
        jj=j;
        if(i>j)
        {
            i=jj;
            j=ii;
        }
        for(k=i;k<=j;k++)
        {
            int num=solve(k,1);
            if(num>maxx)maxx=num;
        }
        printf("%d %d %d\n",ii,jj,maxx);
    }
    return 0;
}
