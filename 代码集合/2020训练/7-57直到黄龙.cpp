#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
using pii = pair<int,int>;
map<string,int> id;
map<int,string> nd;
int N,K,S,D;
string sa,sb;
struct edge
{
    int to,cost;
};
vector<vector<edge> > G;
vector<int> dis,pre,Rc,totalPeo,Numpeo;
vector<int> dealci;
void Dijkstra()
{
    dis = vector<int>(N,0x3f3f3f3f);

    priority_queue<pii,vector<pii>,greater<pii> > pq;

    dis[S] = 0;
    Rc[S] = 1;
    dealci[S] = 0;
    totalPeo[S] = 0;

    pre[S] = -1;
    pq.push({dis[S],S});

    while(!pq.empty())
    {
        auto v  = pq.top();
        pq.pop();

        int x = v.second;

        if(dis[x] < v.first)
            continue;
        
        for(auto &e : G[x])
        {
            if(dis[e.to] > dis[x] + e.cost)
            {
                Rc[e.to] = Rc[x];

                dis[e.to] = dis[x] + e.cost;
                pre[e.to] = x;
                dealci[e.to] = dealci[x] + 1;
                totalPeo[e.to] = totalPeo[x] + Numpeo[e.to];

                pq.push({dis[e.to],e.to});
            }
            else if(dis[e.to] == dis[x] + e.cost)
            {

                 Rc[e.to] += Rc[x];
                //解放最多，杀伤力最强
                if(dealci[e.to] < dealci[x] + 1 || (dealci[e.to] == dealci[x] + 1 &&totalPeo[e.to] < totalPeo[x] + Numpeo[e.to]))
                {
                   

                    dealci[e.to] = dealci[x] + 1;
                    totalPeo[e.to] = totalPeo[x] + Numpeo[e.to];
                    pre[e.to] = x;

                }
            }
        }
    }
}
void printPath(int x)
{
    if(pre[x] == -1)
    {
        cout<<nd[x];
        return;
    }
    printPath(pre[x]);
    cout<<"->"<<nd[x];
}
int main()
{
    cin>>N>>K>>sa>>sb;
    pre.resize(N);
    Rc.resize(N);
    totalPeo.resize(N);
    G.resize(N);
    Numpeo.resize(N);
    dealci.resize(N);
    id[sa] = 0;
    nd[0] = sa;
    S = 0;
    for(int i = 1;i < N;++i)
    {
        string str;
        int l;
        cin>>str>>l;
        id[str] = i;
        nd[i] = str;
        Numpeo[i] = l;
    }
    D = id[sb];
    for(int i = 0;i < K;++i)
    {
        string s,e;
        int le;
        cin>>s>>e>>le;
        int x = id[s], y = id[e];
        G[x].push_back({y,le});
        G[y].push_back({x,le});
    }
    Dijkstra();
    printPath(D);
    cout<<endl;
    cout<<Rc[D]<<" "<<dis[D]<<" "<<totalPeo[D]<<endl;
    return 0;
}