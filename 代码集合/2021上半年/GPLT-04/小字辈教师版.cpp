#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N,maxlevel = 0;
vector<vector<int> > g;
vector<int> d;
vector<int> roots;
void dfs(int x,int level)
{
    d[x] = level;
    for(auto w : g[x])
    {
        if(d[w] == -1)
        {
           // d[w] = level + 1;
            dfs(w,level + 1);
        }
    }
}
int main()
{
    cin>>N;
    roots.resize(N+1);
    g.resize(N+1);
    d.resize(N+1);
    //初始化所有人的辈分为-1这样就不用设置visited了
    fill(d.begin(),d.end(),-1);
    for(int i = 1;i <= N;++i)
    {
        int id;
        cin>>id;
        if(id != -1)
            g[id].push_back(i);
        else 
            roots.push_back(i);
    }
    for(auto root : roots)
        dfs(root,1);
    vector<int> ans;
    int y = *max_element(d.begin(),d.end());
    /*int id = 0;
    for(auto i : d)
    {
        id++;
        if(y == i)ans.push_back(id);
    }*/
    for(int i = 1;i <= N;++i)
        if(d[i] == y)
            ans.push_back(i);

    cout<<y<<endl;
    for(int i  = 0;i < ans.size();++i)
        cout<<ans[i]<<(i < ans.size() -1 ? " " : "\n");
    return 0;
}