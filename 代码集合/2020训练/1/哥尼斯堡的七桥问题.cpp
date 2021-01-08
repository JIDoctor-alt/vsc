#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<queue>
using namespace std;
vector<vector<int> > G;
vector<bool> visted;
int pre[1005];
int N,M, cnt = 0;
int find(int x)
{
    return x == pre[x] ? x : find(pre[x]);
}
void un(int x,int y)
{
    int nx = find(x), ny = find(y);
    if(nx == ny)
        return;
    ++cnt;
   if(nx < ny)
   {
       pre[ny] = nx;
   }
   if(nx > ny)
   {
       pre[nx] = ny;
   }
}
bool judge()
{
    if(cnt != N-1 )
        return false;
    for(int i = 1 ;i <= N;++i)
    {
        if(G[i].size() % 2 != 0)
            return false;
    }

    return true;
}
bool bfs()
{
    int ans = 0;
    fill(visted.begin(),visted.end(),false);
    queue<int> pq;
    pq.push(1);
    visted[1] = true;
  
    while(!pq.empty())
    {
        int v = pq.front();
        ++ans;
        
        pq.pop();
      // cout<<"++ans :"<<ans<<" v : "<<v<<endl;
        for(auto &w : G[v])
        {
            if(!visted[w])
            {
                visted[w] = true;
                
                pq.push(w);
            }
        }
    }

  //  cout<<"ans ==:"<<ans<<endl;
    return (ans == N);
    
}
bool judge1()
{
   
    if(!bfs())
        return false;
     
    for(int i = 1 ;i <= N;++i)
    {
        if(G[i].size() % 2 != 0)
            return false;
    }

    return true;
}
int dfs(int x)
{
    int nans = 1;
    visted[x] = true;
    for(auto &w : G[x])
    {
        if(!visted[w])
        {
            nans += dfs(w);
        }
    }
    return nans;
}
bool judge2()
{
   
   fill(visted.begin(),visted.end(),false);
   int x = dfs(1);
   //cout<<"x == "<<x<<endl;
    if(x != N)
        return false;
     
    for(int i = 1 ;i <= N;++i)
    {
        if(G[i].size() % 2 != 0)
            return false;
    }

    return true;
}
int main()
{

    //ios::sync_with_stdio(false);
    iota(pre,pre + 1005,0);
    cin>>N>>M;
    G.resize(N+1);
    visted.resize(N+1);
    
    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);

        un(x,y);
    }
    //cout<<"cnt = "<<cnt<<endl;

    cout<<(judge2() ? "1\n" : "0\n");
    return 0;
}