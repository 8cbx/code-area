#include<string.h>
#include<stdio.h>
#include<stdlib.h>
char s[10];
int did(int* a)
{
    scanf("%s", s);
    if(s[0]=='E')
    {
        return 0;
    }
    if(s[0]=='B')
    {
        while(did(a));
    }
    else if(s[0]=='L')
    {
        scanf("%s", s);
        int i,t = -1,ta[11];
        memset(ta,0,sizeof(ta));
        if(s[0]!='n')
        {
            t=atoi(s);
        }
        while(did(ta));
        if(t==-1)
        {
            for(i=10; i>0; i--)
            {
                ta[i]=ta[i-1];
            }
            ta[0]=0;
        }
        else
        {
            for(i=0; i<11; i++)
            {
                ta[i]=ta[i]*t;
            }
        }
        for(i=0; i<11; i++)
        {
            a[i]+=ta[i];
        }
    }
    else
    {
        scanf("%s", s);
        a[0]+=atoi(s);
        return did(a);
    }
    return 1;
}
int  main()
{
    int n,i,j,t,a[11];
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        memset(a, 0, sizeof(a));
        did(a);
        printf("Program #%d\n", i);
        printf("Runtime = ");
        t=0;
        for(j=10; j>=0; j--)
        {
            if(a[j]!=0)
            {
                t++;
                if(t!=1)
                {
                    printf("+");
                }
                if(a[j]!=1||j==0)
                {
                    printf("%d", a[j]);
                }
                if(j>0&&a[j]!=1)
                {
                    printf("*");
                }
                if(j>1)
                {
                    printf("n^%d", j);
                }
                if(j==1)
                {
                    printf("n");
                }
            }
        }
        if(!t)
        {
            printf("0");
        }
        printf("\n\n");
    }
    return 0;
}
