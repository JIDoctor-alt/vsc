#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
int N,K;
vector<int> Indegree;
vector<vector<int> > ves;
vector<bool> visited;
int Maxdeep = -1,index_id = -1;
void dfs(int x,int deep)
{
    visited[x] = true;
    if(deep > Maxdeep){
        Maxdeep = deep;
        index_id = x;
    }
    for(auto i : ves[x])
    {
        if(!visited[i]){
            visited[i] = true;
            dfs(i,deep + 1);
        }
    }
}
int main()
{
    cin>>N;
    ves.resize(N+1);
    visited.resize(N+1);
    Indegree.resize(N+1);
    fill(Indegree.begin(),Indegree.end(),0);

    for(int i = 1;i <= N;i++)
    {
        cin>>K;
        while(K--)
        {
            int id;
            cin>>id;
            ves[i].push_back(id);
            Indegree[id]++;
        }
        
    }

    fill(visited.begin(),visited.end(),false);
    int root;
    for(int i = 1;i <= N;i++)
        if(Indegree[i] == 0)
        {
            root = i;
            break;
        }
    dfs(root,1);
    cout<<index_id<<endl;
    return 0;
}