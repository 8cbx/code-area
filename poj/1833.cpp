#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main()
{
    int a[1500];
    int n;
    int k,m;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&n,&k);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        while(k--)
        {
            next_permutation(a,a+n);
        }
        for(int i=0; i<n; i++)
        {
            if(i!=0)
            {
                printf(" ");
            }
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
