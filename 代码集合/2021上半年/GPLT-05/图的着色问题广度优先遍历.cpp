#include<iostream>
#include<set>
#include<vector>
#include<queue>
using namespace std;
int  V,E,K,N;
vector<vector<int> > g;
vector<bool> visited;
vector<int> color;
bool bfs(int x)
{
    queue<int> pq;
    pq.push(x);
    visited[x] = true;
    while (!pq.empty())
    {
        int v = pq.front();
        pq.pop();

        for(auto w : g[v])
        {
            if(color[w] == color[v])
                return false;
            if(!visited[w])
                pq.push(w);
        }
    }
    return true;
    
}
int main()
{
    cin>>V>>E>>K;
    g.resize(V+1);
    visited.resize(V+1);
    color.resize(V+1);
    for(int i = 0;i < E;++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin>>N;
    while(N--)
    {
        set<int> ms;
        for(int i = 1;i <= V;++i)
        {
            int id;
            cin>>id;
            color[i] = id;
            ms.insert(id);
        }
        if(ms.size() != K)
            cout<<"No"<<endl;
        else 
        {
            fill(visited.begin(),visited.end(),false);
            bool flag = true;

            for(int i = 1;i <= V;++i)
            {
                if(!visited[i] && !bfs(i))
                {
                    flag = false;
                    break;
                }
            }
            cout<<(flag ? "Yes\n" : "No\n");
        }
    }
    return 0;
}