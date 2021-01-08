#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int N;
double Z,r;
vector<vector<int> > g;
vector<bool> visited;
vector<int> fn;
double sum = 0;
void dfs(int x,double f)
{
    visited[x] = true;
    if(g[x].size() == 0)
    {
        sum += f*fn[x];
    }

    for(auto &w : g[x])
    {
        if(!visited[w])
        {
            dfs(w,r*f);
        }
    }
}
int main()
{
    cin>>N>>Z>>r;
    g.resize(N);
    visited.resize(N);
    fn.resize(N);
    for(int i = 0;i < N;++i)
    {
        int k;
        cin>>k;
        if(k == 0)
        {
            cin>>fn[i];
        }
        while(k--)
        {
            int xid;
            cin>>xid;
            g[i].push_back(xid);
        }
    }
    r =   ( 1 - 0.01*r);
    dfs(0,Z);
    cout<<(int)sum<<endl;
    return 0;
}