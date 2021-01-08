#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
vector<vector<int> > G;
vector<bool> resotry,visited;
void dfs(int x)
{
    visited[x] = true;

    for(auto &e : G[x])
    {
        if(!visited[e]&&!resotry[e])
            dfs(e);
    }
}
int CountP()
{
    int cnt = 0;
    fill(visited.begin(),visited.end(),false);
    for(int i = 0;i < N;++i)
    {
        if(!visited[i]&&!resotry[i])
        {
            ++cnt;
            dfs(i);
        }
    }
    return  cnt;
}
int main()
{
    cin>>N>>M;
    G.resize(N);
    resotry.resize(N);
    visited.resize(N);


    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int xnum = CountP();
    vector<int> ans;
    ans.push_back(xnum);

    int K;
    cin>>K;
    fill(resotry.begin(),resotry.end(),false);
    for(int i = 0;i < K;++i)
    {
        int id;
        cin>>id;
        resotry[id] = true;
        int renum = CountP();
        if(renum <= ans.back())
        {
            cout<<"City "<<id<<" is lost.\n";
        }
        else
        {
            cout<<"Red Alert: City "<<id<<" is lost!\n";
        }
        
        ans.push_back(renum);
        if(i == N -1)
        {
            cout<<"Game Over.\n";
        }
    }
    return 0;
}