#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using pii = pair<int,int>;
const int MAX = 1005;
struct Edge
{
    int to,w;
};
vector<vector<Edge> > g;
vector<bool> used;
vector<int> d;
int N,M;
int prim()
{
    fill(used.begin(),used.end(),false);
    fill(d.begin(),d.end(),0x3f3f3f3f);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    d[1] = 0;
    pq.push({d[1],1});
    int ans = 0, cnt = 0;
    while(!pq.empty())
    {
        auto v = pq.top();
        pq.pop();
        int x = v.second, w = v.first;
        if(used[x])
            continue;

        ans += d[x];
       // cout<<"{"<<x<<":"<<d[x]<<"} ";
        used[x] = true;
        ++cnt;

        for(auto &e : g[x])
        {
            if(d[e.to] > e.w)
            {
                d[e.to] = e.w;
                pq.push({d[e.to],e.to});
            }
        }
    }
    return cnt == N ? ans : -1;
}
int main()
{
    while(cin>>N&& N)
    {
        cin>>M;
        g.clear();
        g.resize(N+1);
        used.resize(N+1);
        d.resize(N+1);
        
        while(M--)
        {
            int x,y,c;
            cin>>x>>y>>c;
           
        g[x].push_back({y,c});
        g[y].push_back({x,c});
        
        }
        cout<<prim()<<endl;
    }
    
    return 0;
}