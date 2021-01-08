#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<numeric>
using namespace std;
struct Edge
{
    /* data */
    long long s ,to ,w;
};
vector<long long> pre;
vector<Edge> ed;
long long N,M;
long long find(long long x)
{
    return pre[x] == x ? x : find(pre[x]);
}
long long Kruskal()
{
    sort(ed.begin(),ed.end(),[](auto &e1,auto &e2){return e1.w < e2.w;});
    iota(pre.begin(),pre.end(),0);
    long long cnt = 0, ans = 0;
    for(auto &e : ed)
    {
            long long x = e.s , y = e.to ;
            long long nx = find(x);
            long long ny = find(y);
            if(nx == ny)
                continue;
            ans += e.w;
            ++cnt;
            pre[nx] = ny;
    }
    return cnt == N-1 ? ans : -1;
} 
int main()
{
    cin>>N>>M;
    pre.resize(N+1);
    for(int i = 0;i < M;++i)
    {
        long long x,y,c;
        cin>>x>>y>>c;
        ed.push_back({x,y,c});
    }
    cout<<Kruskal()<<endl;
    return 0;
}