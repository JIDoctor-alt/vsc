#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector<vector<int> > G;
vector<bool> visited;
vector<int> temp;
set<int> st;
int max_deep = 0,N;
void dfs(int x,int deep)
{
    visited[x] = true;

    if(deep > max_deep)
    {
        max_deep = deep;
        temp.clear();
        temp.push_back(x);
    }
    else if(deep == max_deep)
    {
        temp.push_back(x);
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
    G.resize(N+1);
    visited.resize(N+1);

    for(int i = 1;i < N;++i)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    fill(visited.begin(),visited.end(),false);
    int ans = 0,s1;
    for(int i = 1;i <= N;++i)
    {
        if(!visited[i])
        {
            dfs(i,1);
            ++ans;
        }
        if(i == 1)
        {
            s1 = temp[0];
            for(int j = 0;j < temp.size();++j)
                st.insert(temp[j]);
        }
    }
    if(ans >= 2)
    {
        cout<<"Error: "<<ans<<" components\n";
    }
    else 
    {
        max_deep = 0;
        fill(visited.begin(),visited.end(),false);
        temp.clear();
        dfs(s1,1);

        for(int j = 0;j < temp.size();++j)
            st.insert(temp[j]);
        for(auto &c : st)
        {
            cout<<c<<endl;
        }
    }
    return 0;
}