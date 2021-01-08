#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
const int MAX = 10005;
int c[MAX];
vector<int> g[MAX];
bool visited[MAX];
int N,M,K;
bool bfs(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        for(auto i : g[x])
        {
            if(c[x] == c[i])
                return false;
            if(!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return true;
}
bool check()
{
    fill(visited,visited + MAX,false);
    for(int i = 0;i < N;++i)
        if(!visited[i]&& !bfs(i))
            return false;
    return true;
}
int main()
{
    cin>>N>>M;
    while(M--)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin>>K;
    while (K--)
    {
        set<int> st;
        for(int i = 0;i < N;++i)
        {
            int x;
            cin>>x;
            st.insert(x);
            c[i] = x;
        }
        int kcnt = st.size();
        if(check())
            cout<<kcnt<<"-coloring\n";
        else 
            cout<<"No\n";
    }
    return 0;
}
