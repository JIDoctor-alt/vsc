#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
using pii = pair<int,int>;
vector<bool> used;
vector<int> dis;
vector<vector<pii> > G;
int N,M;
int prim()
{
    fill(dis.begin(),dis.end(),0-0x3f3f3f3f);
    priority_queue<pii> pq;
    pq.push({0,1});
    dis[1] = 0;
    int cnt = 0,ans = 0;
    while(!pq.empty())
    {
        auto v = pq.top();
        pq.pop();

        int x = v.second,w = v.first;

        if(used[x])
            continue;

        ans += dis[x];
        used[x] = true;
        ++cnt;

        for(auto i : G[x])
        {
            int c = i.first,le = i.second;
            if(dis[c] < le)
            {
                dis[c] =  le;
                pq.push({dis[c],c});
            }
        }
    }
    return cnt == N ? ans : -1;
}
int main()
{
    cin>>N>>M;
    G.resize(N+1);
    dis.resize(N+1);
    used.resize(N+1);
    for(int i = 0; i < M;++i)
    {
        int x,y,c;
        cin>>x>>y>>c;
        G[x].push_back({y,c});
        G[y].push_back({x,c});
    }
    int ans = prim();
    cout<<ans<<endl;
    return 0;
}