#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<vector<int> > g;
vector<bool> visited;
set<int> st;
int maxdeep = -1;
int N,root;
void dfs(int x,int deep)
{
    visited[x] = true;

    if(deep > maxdeep)
    {
        maxdeep = deep;
        st.clear();
        st.insert(x);
    }
    else if(deep == maxdeep)
    {
        st.insert(x);
    }

    for(auto &w : g[x])
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
    g.resize(N+1);
    fill(visited.begin(),visited.end(),false);
    for(int i  = 1;i <= N;++i)
    {
        int xid;
        cin>>xid;
        if(xid == -1)
            root = i;
        else 
            g[xid].push_back(i);
    }
    dfs(root,1);
    cout<<maxdeep<<endl;
    int num = st.size(),ans = 0;
    for(auto &e : st)
    {
        if(ans != 0)
            cout<<" ";
        cout<<e;
        ++ans;
    }
    return 0;
}