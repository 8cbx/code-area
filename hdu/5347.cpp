#include <cstdio>
#include <cstring>
using namespace std;
double atomic[90] =
{
    0,1312,2372.3,520.2,899.5,800.6,1086.5,1402.3,1313.9,1681,2080.7,495.8,737.7,577.5,786.5,1011.8,999.6,1251.2,1520.6,418.8,589.8,633.1,658.8,650.9,652.9,717.3,762.5,760.4,737.1,745.5,906.4,578.8,762,947,941,1139.9,1350.8,403,549.5,600,640.1,652.1,684.3,702,710.2,719.7,804.4,731,867.8,558.3,708.6,834,869.3,1008.4,1170.4,375.7,502.9,538.1,534.4,527,533.1,540,544.5,547.1,593.4,565.8,573,581,589.3,596.7,603.4,523.5,658.5,761,770,760,840,880,870,890.1,1007.1,589.4,715.6,703,812.1,890,1037,380,509.3,499
};
int main()
{
    int u=0, v=0;
    while(scanf("%d%d",&u,&v)!=EOF)
    {
        bool u_greater=false;
        u_greater=atomic[u]>atomic[v];
        if(u_greater)
            printf("FIRST BIGGER\n");
        else
            printf("SECOND BIGGER\n");
    }
    return 0;
}
