#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > G;
vector<bool> visited;
vector<int> d,f;
vector<int> postOrder;
int ts;
bool isDAG;
int N,M;
void dfs(int x)
{
    
}
int main()
{
    cin>>N>>M;
    G.resize(N+2);
    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[0].push_back(y);
        G[y].push_back(N+1);
    }
    

}