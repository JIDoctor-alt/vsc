#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > ves;
vector<bool> visited;
int N,M,K,Np;
//是否能访问
bool dfs(int x)
{
    visited[x] = true;
    for(auto w : ves[x])
    {
        if(!visited[w]){
           // dfs(w);
            return false;
        }      
    }
    return true;
}
bool judge()
{
    for(int i = 1 ;i <= N;++i)
    {   //如果有一个点能访问(深度搜索)就返回false
        if(!visited[i] && !dfs(i))
            return false;
    }
    return true;
}
int main()
{
    cin>>N>>M;
    visited.resize(N+1);
    ves.resize(N+1);

    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        ves[x].push_back(y);
        ves[y].push_back(x);
    }
    cin>>K;
    while (K--)
    {
        fill(visited.begin(),visited.end(),false);

        cin>>Np;
        while (Np--)
        {
            int num;
            cin>>num;
            visited[num] = true;
        }
        cout<<(judge() ? "YES\n" : "NO\n");
        
    }
    
    return 0;
}