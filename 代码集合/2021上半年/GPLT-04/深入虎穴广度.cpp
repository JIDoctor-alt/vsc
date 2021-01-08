#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<vector<int> > g;
vector<bool> visited;
vector<int> indegree;
int N,K;
int MaxDeep = 0 ,ans,Deep = 0;
queue<int> pq;
void bfs(int x)
{
    visited[x] = true;
    pq.push(x);
    ans = x;
    while(!pq.empty())
    {
        int v = pq.front();

        for(auto i : g[v])
        {
            if(!visited[i])
            {
                visited[i] = true;
                pq.push(i);
                Deep++;
                if(Deep > MaxDeep)
                {
                    ans = i;
                    MaxDeep = Deep;
                }
                
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
    indegree.resize(N+1);
    fill(visited.begin(),visited.end(),false);
    fill(indegree.begin(),indegree.end(),0);
    for(int  i = 1;i <= N;i++)
    {
        cin>>K;
        while(K--)
        {
            int  id;
            cin>>id;
            g[i].push_back(id);
            ++indegree[id];
        }
    }
    int root;
    for(int i = 1;i <= N;++i)
        if(indegree[i] == 0)
        {
            root = i;
            break;
        }

    bfs(root);
    cout<<ans<<endl;
    return 0;
}