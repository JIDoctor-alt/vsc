#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using pii = pair<int,int>;
int N;
vector<vector<int> > G;
vector<bool> visited;
vector<int> res;
int root , max_deep = 1;
void bfs()
{
    queue<pii> pq;
    pq.push(make_pair(root,1));
    visited[root] = true;
    while(!pq.empty())
    {
        auto v = pq.front();
        pq.pop();
        int x = v.first;
        if(max_deep < v.second)
        {
            max_deep = v.second;
            res.clear();
            res.push_back(x);
        }
        else if(max_deep == v.second)
        {
            res.push_back(x);
        }
        for(auto w : G[x])
        {

            if(!visited[w])
            {
              visited[w] = true;
              pq.push(make_pair(w,v.second + 1));
            }
        }
    }
}
int main()
{
    cin>>N;
    G.resize(N+1);
    visited = vector<bool>(N+1,false);
    for(int i = 1;i <= N;++i)
    {
        int pre;
        cin>>pre;
        if(pre != -1)
            G[pre].push_back(i);
        else 
            root = i;
    }
    bfs();
    cout<<max_deep<<endl;
    sort(res.begin(),res.end());
    cout<<res[0];
    for(int i = 1;i < res.size();++i)
        cout<<" "<<res[i];
    return 0;
}