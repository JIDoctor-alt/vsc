#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M,K;
vector<vector<int> > ves;
vector<bool> visited;
vector<bool> destory;
void dfs(int x)
{
    visited[x] = true;
    for(auto w :  ves[x])
    {
        if(!visited[w] && !destory[w])
            dfs(w);
    }
}
int cntCi()
{
    fill(visited.begin(),visited.end(),false);
    int ans = 0;
    for(int i = 0;i < N;++i)
    {
        if(!visited[i] && !destory[i])
        {
            dfs(i);
            ++ans;
        }
    }
    return ans;
}
int main()
{
    cin>>N>>M;
    ves.resize(N);
    visited.resize(N);
    destory.resize(N);
    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        ves[x].push_back(y);
        ves[y].push_back(x);
    }
    cin>>K;
    fill(destory.begin(),destory.end(),false);
    
    int cnt = cntCi();
    for(int i = 1;i <= K;++i)
    {
        int num;
        cin>>num;
        destory[num] = true;
        int id = cntCi();
        if(id > cnt)
            cout<<"Red Alert: City "<<num<<" is lost!"<<endl;
        else 
            cout<<"City "<<num<<" is lost."<<endl;
        
        cnt = id;

        if(i == N)
            cout<<"Game Over."<<endl;
    }
    return 0;
}