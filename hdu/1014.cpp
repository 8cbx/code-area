#include<stdio.h>
#include<string.h>
int main()
{
    int ok[100010];
    int seed;
    int step,mod;
    int coun=0;
    while(scanf("%d%d",&step,&mod)!=EOF)
    {
        memset(ok,0,sizeof(ok));
        seed=0;
        coun=0;
        while(ok[seed]==0)
        {
            ok[seed]=1;
            coun++;
            seed=(seed+step)%mod;
        }
        if(coun==mod)
        {
            printf("%10d%10d    Good Choice\n\n",step,mod);
        }
        else
        {
            printf("%10d%10d    Bad Choice\n\n",step,mod);
        }
    }
    return 0;
}
