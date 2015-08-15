#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
vector<int>edge[30010];
int main()
{
    int n,m;
    int t;
    scanf("%d",&t);
    int cou[30010];
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            edge[i].clear();
        }
        memset(cou,0,sizeof(cou));
        for(int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            edge[v].push_back(u);
            cou[u]++;
        }
        priority_queue<int>q;
        for(int i=1;i<=n;i++)
        {
            if(cou[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>res;
        while(!q.empty())
        {
            int now=q.top();
            q.pop();
            res.push_back(now);
            for(int i=0;i<(int)edge[now].size();i++)
            {
                int tmp=edge[now][i];
                cou[tmp]--;
                if(cou[tmp]==0)
                {
                    q.push(tmp);
                }
            }
        }
        for(int i=res.size()-1;i>=0;i--)
        {
            if(i==(int)res.size()-1)
            {
                printf("%d",res[i]);
            }
            else
            {
                printf(" %d",res[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
