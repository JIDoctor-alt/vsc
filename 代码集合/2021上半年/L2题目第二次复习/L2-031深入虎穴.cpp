#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<vector<int> > G;
vector<bool> visited;
vector<int> pre;
int N,K;
int max_deep = 1,index;
void dfs(int x,int deep)
{
    visited[x] = true;
    if(max_deep < deep)
    {
        max_deep = deep;
        index = x;
    }
        
    for(auto w : G[x])
    {
        if(!visited[w])
            dfs(w,deep + 1);
    }
}
int main()
{
    cin>>N;
    G.resize(N+1);
    visited.resize(N+1);
    pre = vector<int>(N+1,-1);
    fill(visited.begin(),visited.end(),false);
    for(int i = 1;i <= N;++i)
    {
        cin>>K;
        while(K--)
        {
            int id;
            cin>>id;
            pre[id] = i;
            G[i].push_back(id);
        }
    }
    int root ;
    for(int i = 1;i <= N;++i)
        if(pre[i] == -1)
        {
            root = i;
            break;
        }
    index = root;
    dfs(root,1);
    cout<<index<<endl;

    return 0;
}