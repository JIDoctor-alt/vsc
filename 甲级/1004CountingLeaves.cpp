#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<vector<int> > tree(100);
vector<bool> visited(100,false);
vector<int> level(100,0);
int n,m,max_deep  = 0;
void dfs(int x,int deep)
{
    visited[x] = true;
    if(tree[x].size() == 0)
        level[deep]++;
    max_deep = max(max_deep,deep);
    for(auto &w : tree[x])
    {
        if(!visited[w])
            dfs(w,deep + 1);
    }
}
int main()
{
    cin>>n>>m;
    while(m--)
    {
        int id,k;
        cin>>id>>k;
        while(k--)
        {
            int x;
            cin>>x;
            tree[id].push_back(x);
        }
    }
    dfs(1,1);

    for(int i = 1;i <= max_deep;++i)
    {
        cout<<level[i];
        if(max_deep != i)
            cout<<" ";
    }
    cout<<endl;
    return 0;;
}