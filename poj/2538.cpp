#include<stdio.h>
#include<string.h>
int main()
{
    char s[50]= {"00VXSWDFGUHJKNBIO0EARYCQZT"};
    char ss;
    int i,len,k;
    k=0;
    while(scanf("%c",&ss)!=EOF)
    {
        if(ss=='\n')
        {
            printf("\n");
        }
        if(ss==' ')
        {
            printf(" ");
        }
        else if(ss<='Z'&&ss>='A')
        {
            printf("%c",s[ss-'A'+1]);
        }
        else if(ss=='0')
        {
            printf("9");
        }
        else if(ss=='-')
        {
            printf("0");
        }
        else if(ss=='=')
        {
            printf("-");
        }
        else if(ss>='1'&&ss<='9')
        {
            printf("%c",ss-1);
        }
        else if(ss=='[')
        {
            printf("P");
        }
        else if(ss==']')
        {
            printf("[");
        }
        else if(ss=='\\')
        {
            printf("]");
        }
        else if(ss==';')
        {
            printf("L");
        }
        else if(ss=='\'')
        {
            printf(";");
        }
        else if(ss==',')
        {
            printf("M");
        }
        else if(ss=='.')
        {
            printf(",");
        }
        else if(ss=='/')
        {
            printf(".");
        }
    }
    return 0;
}
