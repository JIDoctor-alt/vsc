#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
struct edge
{
    int s,to,w;
};
vector<edge> el;
vector<int> pre;
int N,M;
int find(int x)
{
    return pre[x] == x ? x : find(pre[x]);
}
int Kruskal()
{
    int ans = 0,cnt = 0;
    sort(el.begin(),el.end(),[](auto &e1,auto &e2){return e1.w < e2.w;});
    for(auto w : el)
    {
        int x = w.s,y = w.to;
        int nx = find(x);
        int ny = find(y);
        if(nx == ny)
            continue;
        if(nx < ny)
            pre[ny] = nx;
        else
            pre[nx] = ny;
        ans += w.w;
        if(++cnt == N - 1)
            break;
    }
    return cnt == N-1 ? ans : -1;
}
int main()
{
    cin>>N>>M;
    pre.resize(N+1);
    iota(pre.begin(),pre.end(),0);
    for(int i = 0;i < M;++i)
    {
        int x,y,c;
        cin>>x>>y>>c;
        el.push_back({x,y,c});
    }
    cout<<Kruskal()<<endl;
    return 0;
}