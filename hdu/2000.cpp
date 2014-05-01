#include<stdio.h>
#include<string.h>
int main()
{
    char s1,s2,s3,x,y,z;
    while(scanf("%c%c%c",&s1,&s2,&s3)!=EOF)
    {
        x=s1<s2?s1:s2;
        x=x<s3?x:s3;
        z=s1>s2?s1:s2;
        z=s3>z?s3:z;
        y=s1+s2+s3-x-z;
        printf("%c %c %c\n",x,y,z);
        scanf("%c",&s1);
    }
    return 0;
}
