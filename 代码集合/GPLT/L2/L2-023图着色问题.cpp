#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
struct node{
    int x,y;
};
bool flag;
vector<vector<int> > G;
vector<int> color;
vector<bool> visited;
int V,E,K;
bool judge(int x)
{

    queue<node> pq;
    visited[x]  = true;
    pq.push({x,color[x]});
    while(!pq.empty())
    {
        auto v = pq.front();
        pq.pop();

        for(auto &w : G[v.x])
        {
            if(color[w] == v.y)
                return false;
            if(!visited[w])
            {
                visited[w] = true;
                pq.push({w,color[w]});
            }
        }
    }
    return true;
}
int main()
{
    cin>>V>>E>>K;
    G.resize(V+1);
    visited.resize(V+1);
    color.resize(V+1);
    for(int i = 0;i < E;++i)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int N;
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        fill(color.begin(),color.end(),0);

        set<int> st;
        for(int j = 0;j < V;++j)
        {   
            int id;
            cin>>id;
            st.insert(id);
            color[j+1] = id;
        }
        if(st.size() != K)
        {
            cout<<"No"<<endl;
        }
        else{
            flag = true;
            fill(visited.begin(),visited.end(),false);
            for(int d = 1;d <= V;++d)
            {
                if(!visited[d])
                {
                    if(!judge(d))
                    {
                        flag = false;
                        break;
                    }
                }
            }
            cout<<(flag ? "Yes\n" : "No\n");
        }
    }

    return 0;
}