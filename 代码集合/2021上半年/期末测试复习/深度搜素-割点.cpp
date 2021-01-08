#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
vector<vector<int> > G;
int N,M,ts;
vector<bool> Point;
vector<int> d,low;
void dfs(int x,int pa)
{
    low[x] = d[x] = ++ts;
    int child = 0;
    for(auto w : G[x])
    {
        if(d[w] == 0)
        {
            ++child;
            dfs(w,x);
            low[x] = min(low[x],low[w]);

            if(pa != -1 && low[w] >= d[x])
                Point[x] = true;
            
            
        }
        else 
        {
            if(w != pa && d[x] >= d[w])
                low[x] = min(low[x],d[w]);
        }
    }
    if(pa == -1 && child > 1)
        Point[x] = true;
}
int main()
{
    cin>>N>>M;
    G.resize(N+1);
    d.resize(N+1);
    low.resize(N+1);
    Point.resize(N+1);
    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    fill(Point.begin(),Point.end(),false);
    fill(d.begin(),d.end(),0);
    for(int i = 1;i <= N;++i)
    {
        if(d[i] == 0)
        {
            dfs(i,-1);
        }
    }
    int cnt = count_if(Point.begin(),Point.end(),[](auto x){return x;});
    cout<<cnt<<endl;


    return 0;
}