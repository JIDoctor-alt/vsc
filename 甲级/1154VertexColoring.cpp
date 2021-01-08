#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector<vector<int> > G;
vector<bool> visited;
vector<int> color;
set<int> st;
int N,M,k;
bool dfs(int x)
{
    visited[x] = true;
    for(auto &w : G[x])
    {
        if(color[w] == color[x])
            return false;
        if(!visited[w]&&!dfs(w))
            return false;
    }
    return true;
}
bool judge()
{
    fill(visited.begin(),visited.end(),false);
    for(int i = 0;i < N;++i)
    {
        if(!visited[i]&&!dfs(i))
            return false;
    }
    return true;
}
int main()
{
    cin>>N>>M;
    visited.resize(N);
    G.resize(N);
    color.resize(N);

    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cin>>k;
    while(k--)
    {
        set<int> colornum;
        for(int i = 0;i < N;++i)
        {
            cin>>color[i];
            colornum.insert(color[i]);
        }
        int num = colornum.size();

       if(judge())
        {
            cout<<num<<"-coloring\n";
        }
        else 
        {
            cout<<"No\n";
        }
    }
    return 0;
}	