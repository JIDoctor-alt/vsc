#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;
vector<vector<int> > G;
vector<bool> visited;
vector<int> pre;
int root;
int maxdeep = -1,resultindex ;
void dfs(int x,int deep)
{
    visited[x] = true;
    if(maxdeep < deep)
    {
        resultindex = x;
        maxdeep = deep;
    }

    for(auto &w : G[x])
    {
        if(!visited[w])
        {
            dfs(w,deep + 1);
        }
    }
}
int main()
{
 
    cin>>N;
    visited.resize(N+1);
    G.resize(N+1);
    pre.resize(N+1);
       fill(pre.begin(),pre.end(),-1);
    for(int i = 1;i <= N;++i)
    {
        cin>>K;
        while(K--)
        {
            int id;
            cin>>id;
            G[i].push_back(id);
            pre[id] = i;
        }
    }

    for(int i = 1;i <= N;++i)
    {
        if(pre[i] == -1)
        {
            root = i;
            break;
        }
    }
    fill(visited.begin(),visited.end(),false);
    dfs(root,1);
    cout<<resultindex<<endl;
    return 0;
}