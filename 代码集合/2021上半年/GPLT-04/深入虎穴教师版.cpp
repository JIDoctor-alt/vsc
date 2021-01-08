#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > g;
int ans,maxLev = -1;
vector<bool> visited;
vector<int> inDegree;
void dfs(int x,int lev)
{
    visited[x] = true;
    if(g[x].size() == 0)
    {
        if(lev >maxLev)
        {
            maxLev = lev;
            ans = x;
        }
    }
    for(auto i : g[x])
    {
        if(!visited[i])
        {
            visited[i] = true;
            dfs(i,lev + 1);
        }
    }
}
int main()
{
    int N;
    cin>>N;
    g.resize(N+1);
    visited.resize(N+1);
    fill(visited.begin(),visited.end(),false);
    inDegree.resize(N+1);
    fill(inDegree.begin(),inDegree.end(),0);
    for(int i = 1;i <= N;++i)
    {
        int k;
        cin>>k;
        while (k--)
        {
            int x;
            cin>>x;
            g[i].push_back(x);
            ++inDegree[x];
        }
    }
    int root = 1;
    for(int i = 1;i <= N;++i)
        if(inDegree[i] == 0)
            root = i;
    dfs(root,1);
    cout<<ans<<endl;
    return 0;
}