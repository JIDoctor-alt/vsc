#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<int> pre;
int N,maxdeep = -1;
set<int> st;
vector<vector<int> > g;
vector<bool> visited;
void dfs(int x,int deep)
{
    visited[x] = true;
    if(maxdeep < deep)
    {
        st.clear();
        st.insert(x);
        maxdeep = deep;
    }
    else if(maxdeep == deep)
    {
        st.insert(x);
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
    g.resize(N+1);
    visited.resize(N+1);
    int  root;
    for(int i = 1;i <= N;++i)
    {
        int id;
        cin>>id;
        if(id == -1)
            root = i;
        else 
        {
            g[id].push_back(i);
        }
    }
    dfs(root,1);
    cout<<maxdeep<<endl;
    int cnt = 0;
    for(auto &c : st)
    {
        if(cnt != 0)
            cout<<" ";
        ++cnt;
        cout<<c;
    }
    return 0;
}