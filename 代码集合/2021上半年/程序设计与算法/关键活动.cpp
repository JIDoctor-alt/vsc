#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using pii = pair<int,int>;
int N,M,ts;
vector< vector<pii> > g,g1;
vector<int> d,f;
vector<int> pre,postOrder;
vector<int> dis;
vector<pii> path;
vector<int> est,eft,last;
bool isDAG;
void addEdge(int x,int y,int c)
{
    g[x].push_back({y,c});
    g1[y].push_back({x,c});
}
void dfs(int x)
{
    d[x] = ++ts;
    for(auto &e : g[x])
    {
        int i = e.first;
        if(d[i] == 0)
            dfs(i);
        else if(f[i] == 0 && d[i] < d[x])
        {
            isDAG = false;
            return;
        }

    }
   

    f[x] = ++ts;
    postOrder.push_back(x);
    
}
bool topo(){
    bool isDAG = true;
    for(int i = 1;i <= N+2;++i)
        if(d[i] == 0)
            dfs(i);
    return isDAG;
}
void relaxGrap(int x)
{
    for(auto &i : g[x])
    {
        int c = i.first,l = i.second;
        if(dis[c] < dis[x] + l)
        {
            dis[c] = dis[x] + l; 
        }
        if(last[x] > dis[c] - l)
            last[x] = dis[c] - l;
    }
}/*
void lastTime(int x)
{
  fill(last.begin(),last.end(),0x3f3f3f3f);
  queue<int> pq;
  pq.push(x);
  last[x] = dis[x];
   while (!pq.empty())
   {
        
       int v = pq.front();
       pq.pop();
       // cout<<v<<"==";
       for(auto &w : g1[v])
       {
           int c = w.first,l = w.second;
           if(last[c] > last[v] - l)
                last[c] = last[v] - l;
         //   cout<<c<<"==";
           pq.push(c);
       }
   }
}*/

int main()
{
    cin>>N>>M;
    //1 - N+2
    d.resize(N+3);
    f.resize(N+3);
    g.resize(N+3);
    dis.resize(N+3);
    pre.resize(N+3);
    last.resize(N+3);
    g1.resize(N+3);
//    est.resize(N+3);
//    eft.resize(N+3);

    while (M--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        addEdge(x,y,z);
        addEdge(N+1,x,0);
        addEdge(N+1,y,0);

        addEdge(y,N+2,0);
        addEdge(x,N+2,0);
       // g1[y].push_back({x,z});
    }
    if(!topo())
    {
        cout<<"0"<<endl;
    }
    else 
    {
        fill(dis.begin(),dis.end(),0 - 0x3f3f3f3f);
        reverse(postOrder.begin(),postOrder.end());
        dis[N+1] = 0;
        for(auto &w : postOrder)
        {
            relaxGrap(w);
        }
        cout<<dis[N+2]<<endl;
     //   lastTime(N+2);
        /*for(auto e : last)
            cout<<e<<" ";
            cout<<endl;
        for(auto e : dis)
            cout<<e<<" ";
            cout<<endl;*/
        vector<int> result;
        for(int i = 1;i <= N;++i)
            if(dis[i] == last[i])
                result.push_back(i);
        for(int i = 1;i < result.size();++i)
            cout<<result[i-1]<<"->"<<result[i]<<endl;
    }
    return 0;
}