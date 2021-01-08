#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
vector<vector<int> > G;
vector<bool> co_city;
vector<bool> visited;
void dfs(int x)
{
    visited[x] = true;
    for(auto &e : G[x])
    {
        if(!visited[e]&&!co_city[e])
        {
            dfs(e);
        }
    }
}
int judge()
{
    int cnt_id = 0;
    fill(visited.begin(),visited.end(),false);
    for(int i = 0;i < N;++i)
    {
        if(!visited[i]&&!co_city[i])
        {
            dfs(i);
            ++cnt_id;
        }
    }
    return cnt_id;
}
int main()
{
    cin>>N>>M;
    visited.resize(N);
    G.resize(N);
    co_city.resize(N);

    fill(co_city.begin(),co_city.end(),false);

    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int cnt = judge();

    vector<int> ans_fond;
    ans_fond.push_back(cnt);

    int K;
    cin>>K;

    for(int i = 0;i < K;++i)
    {
         int id;
         cin>>id;

         co_city[id] = true;

         cnt = judge();

         if(cnt  >= 1 + ans_fond.back())
         {
             cout<<"Red Alert: City "<<id<<" is lost!\n";
         }
         else 
         {
             cout<<"City "<<id<<" is lost.\n";
         }

         ans_fond.push_back(cnt);

         if(i == N - 1)
            cout<<"Game Over.\n";

    }
    return 0;
}