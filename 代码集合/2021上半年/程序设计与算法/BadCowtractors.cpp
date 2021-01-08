#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using pii = pair<int,int>;
vector<vector<pii> >  g;
vector<bool> used;
vector<int>  d;
int N,M;
int prim()
{
    fill(used.begin(),used.end(),false);
    fill(d.begin(),d.end(),0-0x3f3f3f3f);
    d[1] = 0;
    priority_queue<pii> pq;
    pq.push({d[1],1});
    int ans = 0;
    int cnt = 0;
    while(!pq.empty())
    {
        auto v = pq.top();
        pq.pop();
        int x = v.second, w = v.first;
        if(used[x])
            continue;
        ans += d[x];
        used[x] = true;
        ++cnt;
        for(auto &e : g[x])
        {
            if(d[e.first] < e.second)
            {
                d[e.first] = e.second;
                pq.push({d[e.first],e.first});
            }
        }
    }
    return cnt == N ? ans : -1;
}
int main()
{
    cin>>N>>M;
    used.resize(N+1);
    g.resize(N+1);
    d.resize(N+1);
    while (M--)
    {
        int x,y,c;
        cin>>x>>y>>c;
        g[x].push_back({y,c});
        g[y].push_back({x,c});
    }
    cout<<prim()<<endl;
    
    return 0;
}