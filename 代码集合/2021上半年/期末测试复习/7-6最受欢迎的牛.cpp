#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > rG,G;
vector<int> d,post,cntFlag;
vector<bool> visited;
int N,M,ts = 0,sccNum,ans = 0;
void dfs(int x)
{
    d[x] = ++ts;
    for(auto w : G[x])
    {
        if(d[w] == 0)
            dfs(w);
    }
    post.push_back(x);
}
void rdfs(int x)
{
    cntFlag[x] = sccNum;
    for(auto w : rG[x])
    {
        if(cntFlag[w] == 0)
        {
            rdfs(w);
        }
    }

}
bool dfs3(int x)
{
    ++ans;
    visited[x] = true;
    for(auto w : rG[x])
    {
        if(!visited[w])
            dfs3(w);
    }
}
int sccC()
{
    fill(d.begin(),d.end(),0);
    for(int i = 1;i <= N;++i)
    {
        if(d[i] == 0)
            dfs(i);
    }
    reverse(post.begin(),post.end());
    sccNum = 0;
    for(auto i : post)
    {
        if(cntFlag[i] == 0)
        {
            ++sccNum;
            rdfs(i);
        }
    }
    int cnt = 0;
    for(int i = 1;i <= N;++i)
    {
        if(cntFlag[i] == sccNum)
        {
            fill(visited.begin(),visited.end(),false);
            ans = 0;
            dfs3(i);
            if(ans == N)
                ++cnt;
        }
    }
    return cnt;
}
int main()
{
    cin>>N>>M;
    rG.resize(N+1);
    G.resize(N+1);
    cntFlag.resize(N+1);
    visited.resize(N+1);
    d.resize(N+1);
    while(M--)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        rG[y].push_back(x);
    }
    cout<<sccC()<<endl;

    return 0;
}