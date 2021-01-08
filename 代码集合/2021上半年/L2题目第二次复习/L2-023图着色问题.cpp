#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
vector<vector<int> > G;
vector<bool> visited;
vector<int> color;
int V,E,K,N;
//注意有可能不连通
bool bfs(int x)
{
    queue<int> pq;
    pq.push(x);
    visited[x] = true;
    while(!pq.empty())
    {
        auto v = pq.front();
        pq.pop();

        for(auto w : G[v])
        {
            if(color[v] == color[w])
                return false;
            if(!visited[w])
            {
                visited[w] = true;
                pq.push(w);
            }
        }
    }
    return true;
}
bool judge()
{
    fill(visited.begin(),visited.end(),false);
    for(int i = 1;i <= V;++i)
    {
        if(!visited[i])
        {
            if(!bfs(i))
                return false;
        }
    }
    return true;
}
int main()
{
    cin>>V>>E>>K;
    G.resize(V+1);
    visited.resize(V+1);
    color.resize(V+1);
    for(int i = 0;i < E;++i)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cin>>N;
    for(int i = 0 ; i < N;++i)
    {
        fill(color.begin(),color.end(),0);
        set<int> st;
        for(int j = 1;j <= V;++j)
        {
            cin>>color[j];
            st.insert(color[j]);
        }
           
        if(st.size() != K)
        {
            cout<<"No"<<endl;
        }
        else 
        {
            cout<<(judge() ? "Yes\n" : "No\n");
        }
        
    }

    return 0;
}