#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int  N;
double Z,r;
vector< vector<int> > g;
vector<int> total;
vector<double> level;
double ans = 0;
void bfs(int x)
{
    queue<int> pq;
    pq.push(x);
    while(!pq.empty())
    {
        int v = pq.front();
    
        if(g[v].size() == 0)
        {
            ans += level[v] * total[v];
        }
        else
        {
            for(auto w : g[v])
            {
                level[w] = level[v]*(1-r/100);
                pq.push(w);
            }
        }
        pq.pop();
    }


}
int main()
{
    cin>>N>>Z>>r;
    g.resize(N);
    total = vector<int>(N,0);
    level = vector<double>(N,0.0);
    level[0] = Z;
    for(int i = 0;i < N;i++)
    {
        int k;
        cin>>k;
        if(k)
        {
            while(k--)
            {
                int id;
                cin>>id;
                g[i].push_back(id);
            }
        }
        else 
        {
            int num;
            cin>>num;
            total[i] = num;
        }
    }
    bfs(0);
    cout<<(int)ans<<endl;
    return 0;
}