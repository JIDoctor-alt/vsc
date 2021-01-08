#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX_V = 5005, MAX_E = 200005;
struct Edge
{
    int from,to ,w;
};
Edge edges[MAX_E];
int p[MAX_V];
int N,M;
int kruskal()
{
    int ans = 0, cnt = 0;
    sort(edges, edges + M,[](auto &e1, auto &e2){return e1.w. < e2.w;});
    for(int i = 0;i < M;++i)
    {
        int x = edges[i].from , y = edges[i].to ,w = edges[i].w;
        x = find(x), y = find(y);
        if(x == y)
            continue;
        ans += w;
        p[x] = y;
        if(++cnt == N - 1)//所有边查询完毕
            break;
    }
    return cnt == N - 1 ? ans : -1;//输出最短路径
}
int main()
{
    cin>>N>>M;
    for(int i = 0;i < M;++i)
        cin>>edges[i].from>>edges[i].to>>edges[i].w;
        iota(p, p + N + 1, 0);
        int ans = kruskal();
        cout<<ans<<endl;
    return 0;
}