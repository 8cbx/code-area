#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int m=n-1;
        int s=0;
        for (int i=2; i<=n; i++)
        {
            s=(s+m)%i;
            m--;
        }
        printf ("%d\n", s+1);
    }
    return 0;
}
