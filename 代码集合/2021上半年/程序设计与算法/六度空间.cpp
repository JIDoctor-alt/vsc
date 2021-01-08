#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<iomanip>
using namespace std;
vector<int> g[1005];
int d[1005];
int N,M;
int bfs(int x)
{
    int ans = 1;
    queue<int> q;
    d[x] = 0;
    q.push(x);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if(d[u] >= 6)
            continue;
        for(auto v : g[u])
        {
            if(d[v] != -1)
                continue;
            ++ans;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    return ans;
}
int main()
{
    cin>>N>>M;
    while(M--)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 1;i <= N;++i)
    {
        fill(d,d+1005,-1);
        int cnt = bfs(i);
        cout<<i<<": "<<fixed<<setprecision(2)<<(cnt * 100.0 / N)<<"%"<<endl;
    }
    return 0;
}