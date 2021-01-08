#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
double Z,r,ans = 0;
vector<vector<int> > g;
vector<int> total;
vector<bool> visited;
void dfs(int x,double p)
{
    visited[x] = true;
    if(g[x].size() == 0)
        ans += total[x] * p;
    for(auto w : g[x])
    {
        if(!visited[w])
        {
            visited[w] = true;
            dfs(w,p*(1-r/100));
        }
         
    }
}
int main()
{
    cin>>N>>Z>>r;
    g.resize(N);
    visited.resize(N);
    total.resize(N);
    fill(visited.begin(),visited.end(),false);
    fill(total.begin(),total.end(),0);
    for(int i = 0;i < N;++i)
    {
        int k;
        cin>>k;
        if(!k)
        {
            int num;
            cin>>num;
            total[i] = num;
        }
        else
        {
            while(k--)
            {
            int id;
            cin>>id;
            g[i].push_back(id);
            }
            
        }
    }
    dfs(0,Z);
    cout<<(int)ans<<endl;
    return 0;
}