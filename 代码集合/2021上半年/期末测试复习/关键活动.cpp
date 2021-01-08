#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using Edge = pair<int,int>;
using Activity = pair<int,int>;
vector<vector<Edge> > G;
vector<Activity> ans;
vector<int> d,f;
vector<int> postOrder;
vector<int> dis;
vector<vector<int> > pre;
vector<bool> visited;
bool isDAG;
int N,M,ts;
void addEdge(int x,int y,int c)
{
    G[x].push_back({y,c});
}
void dfs(int x)
{
    d[x] = ++ts;
    for(auto i : G[x])
    {
        int c = i.first;
        if(d[c] == 0)
            dfs(c);
        else if(f[c] == 0 && d[c] < d[x])
        {
            isDAG = false;
            return;
        }
    }
    f[x] = ++ts;
    postOrder.push_back(x);
}
void topSort()
{
    isDAG = true;
    dfs(0);
    if(isDAG)
        reverse(postOrder.begin(),postOrder.end());
}
void relaxNode(int x)
{
    for(auto e : G[x])
    {
        int c = e.first,w = e.second;
        if(dis[c] < dis[x] + w)
        {
            dis[c] = dis[x] + w;
            pre[c].clear();
            pre[c].push_back(x);
        }else if(dis[c] == dis[x] + w)
        {
            pre[c].push_back(x);
        }
    }
}
void rDFS(int x)
{
    visited[x] = true;
    for(auto w : pre[x])
    {
        if(!visited[w])
        {
            rDFS(w);
        }
        ans.push_back({w,x});
    }
}
int main()
{
    cin>>N>>M;
    G.resize(N+2);
    d.resize(N+2);
    f.resize(N+2);
    dis.resize(N+2);
    pre.resize(N+2);
    visited.resize(N+2);
    while(M--)
    {
        int x,y,c;
        cin>>x>>y>>c;
        addEdge(x,y,c);
        addEdge(0,x,0);
        addEdge(y,N+1,0);
    }
    topSort();
    if(!isDAG)
    {
        cout<<0<<endl;
    }
    else
    {
        fill(dis.begin(),dis.end(),0 - 0x3f3f3f3f);
        dis[0] = 0;
        for(auto w : postOrder)
        {
            relaxNode(w);
        }
        cout<<dis[N+1]<<endl;
        fill(visited.begin(),visited.end(),false);
        rDFS(N+1);
        sort(ans.begin(),ans.end(),[](auto &a1,auto &a2){return a1.first == a2.first ? a1.second > a2.second : a1.first < a2.first;});
        for(auto &w : ans)
        {
            if(w.first == 0 || w.second == N+1)
                continue;
            cout<<w.first<<"->"<<w.second<<endl;
        }
    }
    return 0;
}