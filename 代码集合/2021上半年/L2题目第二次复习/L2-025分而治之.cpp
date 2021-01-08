#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int> > ves;
vector<bool> visited;
int N,M;
bool dfs(int x)
{
    visited[x] = true;
    for(auto w : ves[x])
    {
        if(!visited[w])
            return false;
    }
    return true;
}
bool judge()
{
    for(int i = 1;i <= N;++i)
    {
        if(!visited[i])
         {
            if(!dfs(i))
            {
                return false;
            }
         }
    }
    return true;
}
int main()
{
    cin>>N>>M;
    ves.resize(N+1);
    visited.resize(N+1);
    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        ves[x].push_back(y);
        ves[y].push_back(x);
    }
    int K;
    cin>>K;
    while(K--)
    {
        int Np;
        cin>>Np;
        fill(visited.begin(),visited.end(),false);
        while(Np--)
        {
            int id;
            cin>>id;
            visited[id] = true;
        }
        cout<<(judge() ? "YES\n" : "NO\n");
    }
    return 0;
}