#include <iostream>
#include <algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
const int maxint = 999999;
typedef struct Road
{
    int c1, c2;
    int value;
} Road;

int no;
int line;
Road road[1000*1000*2+50];
int node[1010*1010];

bool myCmp(const Road &a, const Road &b)
{
    if(a.value < b.value)
        return 1;
    return 0;
}
int Find_Set(int n)
{
    if(node[n] == -1)
        return n;
    return node[n] = Find_Set(node[n]);
}

bool Merge(int s1, int s2)
{
    int r1 = Find_Set(s1);
    int r2 = Find_Set(s2);
    if(r1 == r2)
    return 0;
    if(r1 < r2)
        node[r2] = r1;
    else
        node[r1] = r2;
    return 1;
}
int maz[1010][1010];
int ab(int a,int b)
{
    return a>b?(a-b):(b-a);
}
int main()
{
    int t;
    int cases=0;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        printf("Case #%d:\n",cases);
        int nn;
        int mm;
        scanf("%d%d",&nn,&mm);
        memset(node, -1, sizeof(node));
        for(int i=1; i<=nn; i++)
        {
            for(int j=1; j<=mm; j++)
            {
                scanf("%d",&maz[i][j]);
            }
        }
        line=0;
        no=0;
        for(int i=1; i<=nn; i++)
        {
            if(i!=nn)
            {
                road[line].c1=(i-1)*mm+1;
                road[line].c2=i*mm+1;
                road[line].value=ab(maz[i+1][1],maz[i][1]);
                line++;
            }
            for(int j=2; j<=mm; j++)
            {
                road[line].c1=(i-1)*mm+j;
                road[line].c2=(i-1)*mm+j-1;
                road[line].value=ab(maz[i][j],maz[i][j-1]);
                line++;
                if(i!=nn)
                {
                    road[line].c1=(i-1)*mm+j;
                    road[line].c2=i*mm+j;
                    road[line].value=ab(maz[i+1][j],maz[i][j]);
                    line++;
                }
            }
        }
        no=nn*mm;
        sort(road, road+line, myCmp);
        int sum = 0, count = 0;
        for(int i=0; i<line; ++i)
        {
            if(Merge(road[i].c1, road[i].c2))
            {
                count ++;
                sum += road[i].value;
            }
            if(count == no-1)
                break;
        }
        cout << sum << endl;
    }
    return 0;
}
