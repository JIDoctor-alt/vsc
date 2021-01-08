#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
double Z;
double r,ans = 0;
vector<vector<int> > G;
vector<int> visited;
vector<int> flag;
void dfs(int x,double energy)
{

    visited[x] = 1;

    if(flag[x])
    {

        ans += energy*flag[x];
        return;
    }

    for(auto &e : G[x])
    {
        if(!visited[e])
        {
            dfs(e,energy*(1 - r * 0.01));
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>N>>Z>>r;

    G.resize(N);


    visited.resize(N);

    flag.resize(N);

    fill(flag.begin(),flag.end(),0);

    fill(visited.begin(),visited.end(),0);

    int K;

    for(int i = 0;i < N;++i)
    {
        cin>>K;

        if(K == 0)
        {
            int id;
            cin>>id;
            flag[i] = id;

        }
        while(K--)
        {

            int id;
            cin>>id;

            G[i].push_back(id);

        }
        
    }

    dfs(0,Z);
    cout<<(int)ans;
    return 0;
}