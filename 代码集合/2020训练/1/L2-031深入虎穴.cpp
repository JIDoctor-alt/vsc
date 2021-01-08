#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > g;
vector<bool> visited;
vector<int> pre;
int N;
int K,maxdeep = -1,indexflag;
void dfs(int x,int deep)
{
    visited[x] = true;

    if(deep > maxdeep)
    {
        indexflag = x;
        maxdeep = deep;
    }

    for(auto &w : g[x])
    {
        if(!visited[w])
            dfs(w,deep + 1);
    }
}
int main()
{
    cin>>N;

    visited.resize(N+1);
    g.resize(N+1);

    pre = vector<int>(N+1,-1);


    for(int i = 1;i <= N;++i)
    {
        cin>>K;
        while(K--)
        {
            int id;
            cin>>id;
            g[i].push_back(id);
            pre[id] = i;
        }
    }
    int root;

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
    cout<<indexflag<<endl;
    return 0;
}