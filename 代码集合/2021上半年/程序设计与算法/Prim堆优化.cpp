#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
using pii = pair<int,int>;
const int MAX_V = 5005;
struct Edge
{
    int to,w;
};
vector<Edge> g[MAX_V];
int d[MAX_V];
bool used[MAX_V];
int N,M;
int prim()
{
    int ans = 0, cnt = 0;
    fill(d, d + N + 1,0X3f3f3f3f);
    d[1] = 0;
    priority_queue<pii,vector<pii>, greater<pii>> q;
    q.push({0,1});
    while(!q.empty())
    {
        auto e = q.top();
        q.pop();
        int x = e.second, w = e.first;
        //假设d[4] = 5时已经加入， 后面的过程中d[4] = 1再加入队列就不用在判断了
        if(used[x])
            continue;
        ++cnt;//用来判断是否所有节点都检查过
        ans += d[x];
        used[x] = true;
        for(auto &i : g[x])
        {
            if(d[i.to] > i.w)
            {
                d[i.to] = i.w;
                q.push({d[i.to],i.to});
            }
        }
    }   
    return cnt == N ? ans : -1;
}
int main()
{
    cin>>N>>M;
    while (M--)
    {
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    int ans = prim();
    cout<<ans<<endl;
    return 0;
}
/*
6 10
1 2 6
2 3 5
1 3 1
1 4 5
3 4 5
2 5 3
3 5 6
5 6 6
3 6 4
4 6 2
*/