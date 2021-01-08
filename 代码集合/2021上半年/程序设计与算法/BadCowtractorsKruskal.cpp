#include<iostream>
#include<algorithm>
#include<queue>
#include<numeric>
#include<vector>
using namespace std;
struct Edge
{
    int from , to ,w;
};
vector<int> pre;
vector<Edge> g;
int N,M;
int find(int x)
{
    return pre[x] == x ? x : find(pre[x]);
}
bool cmp(Edge &e1,Edge &e2)
{
    return e1.w > e2.w;
}
int kruskal()
{
    //sort(g.begin(),g.end(),[](auto &e1 ,auto &e2){return e1.w > e2.w;});
    sort(g.begin(),g.end(),cmp);
    int ans = 0, cnt = 0;
    for(auto &e : g)
    {
        int x = e.from, y = e.to ,w = e.w;
        x = find(x);
        y = find(y);
        if(x == y)
            continue;
        ans += w;
        pre[x] = y;
        if(++cnt == N-1)
            break;
    }
    return cnt == N-1 ? ans : -1;
}
int main()
{
    cin>>N>>M;
    pre.resize(N+1);
    for(int i = 0;i < M;++i)
    {
        int x,y,c;
        cin>>x>>y>>c;
        g.push_back({x,y,c});
    }
    iota(pre.begin(),pre.end(),0);
    cout<<kruskal()<<endl;
    return 0;
}