#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int i,j,k,n,l;
    char s;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        priority_queue<int,vector<int>,greater<int> >q;
        scanf("%c",&s);
        for(i=1;i<=n;i++)
        {
            scanf("%c",&s);
            if(s=='I')
            {
                scanf("%d%c",&j,&s);
                q.push(j);
                if(q.size()>k)
                {
                    q.pop();
                }
            }
            else if(s=='Q')
            {
                scanf("%c",&s);
                printf("%d\n",q.top());
            }

        }
    }
    return 0;
}
