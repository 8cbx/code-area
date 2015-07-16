#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int a[10];
    int i=0;
    char tmp;
    while(scanf("%c",&tmp)!=EOF)
    {
        if(tmp>='0'&&tmp<='9')
        {
            a[i]=tmp-'0';
            i++;
        }
    }
    sort(a,a+i);
    do
    {
        for(int j=0;j<i;j++)
        {
            printf("%d",a[j]);
        }
        printf("\n");
    }while(next_permutation(a,a+i));
    return 0;
}
