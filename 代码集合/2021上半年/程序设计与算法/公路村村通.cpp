#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using  namespace std;
struct Edge
{
    int from,to ,w;
};
vector<Edge> g;
vector<int> pa;
int N,M;
int find(int x)
{
    return pa[x] == x ? x : find(pa[x]);
}
int kruscal()
{
    int ans = 0,cnt  = 0;
    sort(g.begin(),g.end(),[](auto &e1 ,auto &e2){return e1.w < e2.w;});
    
    for(auto &e : g)
    {
        int x = e.from, y = e.to ,w = e.w;
        x = find(x);
        y = find(y);
        if(x == y)
            continue;
        ans += w;
        pa[x] = y;
        if(++cnt == N - 1)
            break;
    }
    return cnt == N - 1 ? ans : -1;
}
int main()
{
    
    cin>>N>>M;
    pa.resize(N+1);
    iota(pa.begin(),pa.end(),0);
    for(int i = 0;i < M;++i)
    {
        int x,y,c;
        cin>>x>>y>>c;
        g.push_back({x,y,c});
    }
    cout<<kruscal()<<endl;
    return 0;
}