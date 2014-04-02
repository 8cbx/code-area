#include<stdio.h>
int main()
{
 int n,m;
 int a[10][4] = {{0},{1},{6,2,4,8},{1,3,9,7},{6,4},{5},{6},{1,7,9,3},{6,8,4,2},{1,9}},d,num;


    while(scanf("%d%d",&n,&m)!=EOF)
 {
    d = n % 10;
    if(d == 0||d == 1||d == 5||d == 6)
         printf("%d\n",d);
    else if(d == 4||d == 9)
         printf("%d\n",a[d][m % 2]);
    else if(d == 2||d == 3||d == 7||d == 8)
         printf("%d\n",a[d][m % 4]);
 }

 return 0;
}
