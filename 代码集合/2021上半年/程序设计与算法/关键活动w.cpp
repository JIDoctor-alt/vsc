#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using pii = pair<int,int>;
vector<vector<pii> > G ,rG;
vector<int> d,f,dis;
int ts,N,M;
vector<int> postOrder;
vector<vector<int> > pre;
vector<pii> res;
vector<bool> visited;
bool isDAG;
void dfs(int x)
{
    d[x] = ++ts;
    for(auto w : G[x])
    {
        if(d[w.first] == 0)
        {
            dfs(w.first);
        }else if(d[w.first] < d[x] && f[w.first] == 0)
        {
            isDAG = false;
            return ;
        }
    }
    f[x] = ++ts;
    postOrder.push_back(x);
}
bool topSort()
{
    isDAG = true;
    dfs(0);
    return isDAG;
}
void relax_V(int x)
{
    for(auto w : G[x])
    {
        if(dis[w.first] < dis[x] + w.second)
        {
            dis[w.first] = dis[x] + w.second;
            pre[w.first].clear();
            pre[w.first].push_back(x);
        }else if(dis[w.first] == dis[x] + w.second)
        {
            pre[w.first].push_back(x);
        }
    }
}
void rdfs(int x)
{
    visited[x] = true;
    for(auto w : pre[x])
    {
        if(!visited[w])
        {
            rdfs(w);
           
        }
        res.push_back({w,x});//单起点，单终点
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
    for(int i = 0;i < M;++i)
    {
        int x,y,c;
        cin>>x>>y>>c;
        G[x].push_back({y,c});
        G[0].push_back({x,0});
        G[y].push_back({N+1,0});
    }
    if(!topSort())
    {
        cout<<"0"<<endl;
    }
    else 
    {
        fill(dis.begin(),dis.end(),0 - 0x3f3f3f3f);
        reverse(postOrder.begin(),postOrder.end());
        dis[0] = 0;
        for(auto i : postOrder)
        {
            relax_V(i);
        }
        fill(visited.begin(),visited.end(),false);
        rdfs(N+1);
        cout<<dis[N+1]<<endl;
        sort(res.begin(),res.end(),[](auto &e1,auto &e2){if(e1.first != e2.first)return e1.first < e2.first ; else return e1.second > e2.second;});
        for(auto w : res)
        {
            if(w.first == 0 || w.second == N+1)
                continue;
            cout<<w.first<<"->"<<w.second<<endl;
        }
        
        
    }
    
    return 0;
}