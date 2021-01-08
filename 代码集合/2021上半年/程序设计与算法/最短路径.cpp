#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using pii = pair<int,int>;
vector< vector<pii> > g;
vector<int> dis;
vector<int> d,f;
vector<int> postOrder;
int N,M,ts;
bool isDAG;
vector<int> result,pre;
void addEdge(int x,int y,int c)
{
    g[x].push_back({y,c});
}
void dfs(int x)
{
    d[x] = ++ts;
    for(auto &w: g[x])
    {
        int i = w.first;
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
    isDAG = true;
    for(int i = 0;i < N+2;++i)
    {
        if(d[i] == 0)
            dfs(i);
    }
    return isDAG;
}
void relaxOp(int i)
{
    for(auto &e : g[i])
    {
        int c = e.first,len = e.second;
        if(dis[c] < dis[i] + len){
             dis[c] = dis[i] + len;
             pre[c] = i;
        }
           
    }
}
void printPath(int x)
{
    if(x == N)
    {
        result.push_back(x);
        return;
    }
    printPath(pre[x]);
    result.push_back(x);
}
int main()
{
    cin>>N>>M;
    g.resize(N+2);
    d.resize(N+2);
    f.resize(N+2);
    dis.resize(N+2);
    pre.resize(N+2);
    while (M--)
    {
        int x , y , c;
        cin>>x>>y>>c;
        addEdge(x,y,c);
        addEdge(N,y,0);
        addEdge(N,x,0);
        addEdge(x,N+1,0);
        addEdge(y,N+1,0);
    }
    if(!topo())
        cout<<"Impossible"<<endl;
    else 
    {
        fill(dis.begin(),dis.end(),0-0x3f3f3f3f);
        reverse(postOrder.begin(),postOrder.end());
        dis[N] = 0;
        for(auto &w : postOrder)
            relaxOp(w);
        cout<<dis[N+1]<<endl;
        pre[N] = -1;
        for(int i = 0;i < N+2;i++)
            cout<<i<<" ";
        cout<<endl;
        for(int i = 0;i < N+2;i++)
            cout<<pre[i]<<" ";
            cout<<endl;
    }
    return 0;
}