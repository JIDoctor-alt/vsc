#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX_V = 1000000;
struct Edge
{
    long long to,w;
};
vector<Edge> g[MAX_V];
long long d[MAX_V];
bool used[MAX_V];
long long N,M;
long long prim()
{
    long long ans = 0;
    fill(d,d + N + 1,0x3f3f3f3f);
    d[1] = 0;
    while(true)
    {
        //
        long long x = -1;//用来选择不在生成树中，边权值最小的点
        for(long long i = 1;i <= N;++i)//没有选的   （第一个选的或者是d值小的）
            if(!used[i] && (x == -1 || d[i] < d[x]))
                x = i;
        if(x == -1)//找不到直接退出循环
            break;
        //这种情况意味着有些节点不再生成树中，即该图不连通
        if(d[x] == 0x3f3f3f3f)//如果求最小生成树构成的森林。将该种情况删掉即可
            return -1;
        
        ans += d[x];//累加最小权值
        used[x] = true;//设置已经添加了
        //更新该加入点的邻接点的权值
        for(auto &e : g[x])
            d[e.to] = min(d[e.to],e.w);
    }
    return ans;
}
int main()
{
    cin>>N>>M;
    while (M--)
    {
        long long x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    long long ans = prim();
    cout<<ans<<endl;
    return 0;
}