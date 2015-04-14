#include<stdio.h>
#include<string.h>
int ox(int l)
{
    int ans=0;
    while(l>16)
    {
        ans+=l%16;
        l/=16;
    }
    ans+=l;
    return ans;
}
int xo(int l)
{
    int ans=0;
    while(l>12)
    {
        ans+=l%12;
        l/=12;
    }
    ans+=l;
    return ans;
}
int main()
{
    for(int i=1;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=9;k++)
            {
                for(int l=0;l<=9;l++)
                {
                    if(i+j+k+l==ox(1000*i+100*j+10*k+l)&&i+j+k+l==xo(1000*i+100*j+10*k+l))
                    {
                        printf("%d%d%d%d\n",i,j,k,l);
                    }
                }
            }
        }
    }
    return 0;
}
