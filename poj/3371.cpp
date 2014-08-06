#include<stdio.h>
#include<string.h>
int yy(char a)
{
    if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u' || a=='y'||a=='A' || a=='E' || a=='I' || a=='O' || a=='U' || a=='Y')
    {
        return 1;
    }
    return 0;
}
int jz(char a)
{
    if(a=='.' || a=='?'  || a==':' || a==';' || a=='!')
    {
        return 1;
    }
    return 0;
}
int fg(char a)
{
    if(a==',')
    {
        return 1;
    }
    return 0;
}
int zm(char a)
{
    if(a>='A' && a <='Z')
    {
        return 1;
    }
    if(a>='a' && a <='z')
    {
        return 1;
    }
    return 0;
}
int main(void)
{
    char word[1000];
    int wd,st,sy;
    int wdlen,flag,syl,i;
    wd=0;
    st=0;
    sy=0;
    while(scanf("%s",word)!=EOF)
    {
        wdlen=0;
        flag=0;
        syl=0;
        for(i=0; word[i]; i++)
        {
            if(zm(word[i])==1)
            {
                wdlen++;
                if(wdlen<=3)
                {
                    if(zm(word[i+1])==0)
                    {
                        sy++;
                        sy-=syl;
                        syl=0;
                        continue;
                    }
                }
                if(yy(word[i])==1)
                {
                    if(word[i]=='e')
                    {
                        if(!zm(word[i+1])&& word[i-1]=='l')
                        {
                            sy++;
                            syl++;
                            continue;
                        }
                        else if(zm(word[i+1])==0)
                            continue;
                        else if((word[i+1]=='d' || word[i+1]=='s') && (zm(word[i+2])==0))
                            continue;
                    }
                    if(flag==0)
                    {
                        flag=1;
                        sy++;
                        syl++;
                        continue;
                    }
                    else
                    {
                        continue;
                    }
                }
                flag=0;
            }
            else if(fg(word[i])==1)
            {
                flag=0;
                wdlen=0;
                syl=0;
                wd++;
            }
            else if(jz(word[i])==1)
            {
                flag=0;
                wdlen=0;
                wd++;
                syl=0;
                st++;
            }
        }
        if(zm(word[i-1])==1)
            wd++;
    }
    printf("%.2lf\n",206.835-1.015*(double)wd/(double)st-84.6*(double)sy/(double)wd);
    return 0;
}
