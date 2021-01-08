#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int N,root;
vector<bool> visited;
vector<vector<int> > g;
vector<int> level;
int maxLevel = 0;
queue<int> pq;
void bfs(int x,int levedeep)
{
    visited[x] = true;
    level[x] = levedeep;
    maxLevel = levedeep;
    pq.push(x);
    while (!pq.empty())
    {
        int v = pq.front();
        for(auto i : g[v])
        {
            if(!visited[i])
            {
                level[i] = level[v] + 1;
                if(level[i] > maxLevel)
                    maxLevel = level[i];
                pq.push(i);
            }
        }
        pq.pop();
    }
    
}
int main()
{
    cin>>N;
    g.resize(N+1);
    visited.resize(N+1);
    level.resize(N+1);
    for(int i = 1;i <= N;++i)
    {
        int id;
        cin>>id;
        //id为第i位成员的父、母
        if(id != -1)
        g[id].push_back(i);
        //记录老祖宗的编号
        if(id == -1)root = i;
    }
    fill(visited.begin(),visited.end(),false);
    fill(level.begin(),level.end(),0);
    level[root] = 1;
    bfs(root,1);
    cout<<maxLevel<<endl;
    int flag = 0;
    for(int i = 1;i <= N;++i)
    {
        if(level[i] == maxLevel)
        {
            
            if(flag)cout<<" ";
            cout<<i;
            flag = 1;
        }
    }
    return 0;
}