#include<iostream>
#include<set>
#include<vector>
using namespace std;
int  V,E,K,N;
vector<vector<int> > g;
vector<bool> visited;
vector<int> color;
bool dfs(int x)
{
    visited[x] = true;
    for(auto w : g[x])
    {
        if(color[w] == color[x])
            return false;
        if(!visited[w] && !dfs(w)) 
            return false;  
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
                if(!visited[i] && !dfs(i))
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