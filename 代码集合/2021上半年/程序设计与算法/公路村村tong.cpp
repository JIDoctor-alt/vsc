#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
struct Edge
{
    int from , to ,w;
};
vector<Edge> edge;
vector<int> pre;
int N,M;
int find(int x)
{
    return pre[x] == x ? x : find(pre[x]);
}
int kruskal()
{
    sort(edge.begin(),edge.end(),[](auto  &e1, auto  &e2){return e1.w < e2.w;});
    int ans = 0, cnt = 0;
    for(auto &i : edge)
    {
        int x = i.from , y = i.to , w = i.w;
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
        edge.push_back({x,y,c});
    }
    iota(pre.begin(),pre.end(),0);
    cout<<kruskal()<<endl;
    return 0;
}