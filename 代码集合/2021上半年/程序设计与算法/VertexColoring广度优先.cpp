#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector< vector<int> > G;
vector<int> color;
vector<bool> visited;
set<int> st;//颜色的个数
bool isFlag;
int N,M,K;
void bfs(int x)
{
    visited[x] = true;
    queue<int> pq;
    pq.push(x);
    while(!pq.empty())
    {
        int v = pq.front();
        pq.pop();
        for(auto w : G[v])
        {
            if(color[w] == color[v])
            {
                isFlag = false;
                break;
            }
                
            if(!visited[w])
            {
                visited[w] = true;
                pq.push(w);
            }
        }
    }
}
int main()
{
    cin>>N>>M;
    G.resize(N);
    visited.resize(N);
    color.resize(N);
    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cin>>M;
    while (M--)
    {
        st.clear();
        fill(visited.begin(),visited.end(),false);
        isFlag = true;
        for(int i = 0;i < N;++i)
        {
            int id;
            cin>>id;
            color[i] = id;
            st.insert(id);
        }
        for(int i = 0;i < N;++i)
        {
            if(!visited[i])
                bfs(i);
        }
        if(isFlag)
            cout<<st.size()<<"-coloring"<<endl;
        else 
            cout<<"No"<<endl;
    }
    return 0;
}
