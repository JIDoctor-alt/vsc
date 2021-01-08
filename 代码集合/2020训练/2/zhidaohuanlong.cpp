#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<queue>
using namespace std;
using pii = pair<int,int>;
struct edge
{
    int to,le;
};
int N,K,S,D;
map<string,int> id;
map<int,string> nm;
vector<vector<edge> > g;
vector<int> Rc,pre;
vector<int> totalPeo;
vector<int> num,dis,relaxNum;
string pa,pb;
void Dijsktra()
{
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    Rc[S] = 1;
    totalPeo[S] = 0;
    dis = vector<int>(N,0x3f3f3f3f);
    dis[S] = 0;
    pre[S] = -1;
    pq.push({dis[S],S});
    relaxNum[S] = 0;

    while(!pq.empty())
    {
        auto v = pq.top();
        pq.pop();

        int x = v.second;
        if(dis[x] < v.first)
            continue;
        
        for(auto &e : g[x])
        {
            if(dis[e.to] > dis[x] + e.le)
            {
                Rc[e.to] = Rc[x];
                dis[e.to] = dis[x] + e.le;
                totalPeo[e.to] = num[e.to] + totalPeo[x];
                relaxNum[e.to] = relaxNum[x] + 1;

                pre[e.to] = x;

                pq.push({dis[e.to],e.to});
            }
            else if(dis[e.to] == dis[x] + e.le)
            {
                Rc[e.to] += Rc[x];

                if(relaxNum[e.to] < relaxNum[x] + 1 ||(relaxNum[e.to] == relaxNum[x] + 1 && totalPeo[e.to] < totalPeo[x] + num[e.to]))
                {
                    relaxNum[e.to] = relaxNum[x] + 1;
                    pre[e.to]  = x;
                    
                    totalPeo[e.to] = totalPeo[x] + num[e.to];
                }
            }
        }
    }
}
void PrintPath(int x)
{
    if(pre[x] == -1)
    {
        cout<<nm[x];
        return;
    }
    PrintPath(pre[x]);
    cout<<"->"<<nm[x];
}
int main()
{
    cin>>N>>K>>pa>>pb;
    g.resize(N);
    Rc.resize(N);
    relaxNum.resize(N);
    totalPeo.resize(N);
    num.resize(N);
    pre.resize(N);

    id[pa] = 0;
    nm[0] = pa;

    for(int i = 1;i < N;++i)
    {
        string x;
        int peonum;
        cin>>x>>peonum;
        id[x] = i;
        nm[i] = x;
        num[i] = peonum;
    }
    D = id[pb];

    for(int i = 0;i < K;++i)
    {
        string nx,ny;
        int d;
        cin>>nx>>ny>>d;
        int sx = id[nx], sy = id[ny];
        g[sx].push_back({sy,d});
        g[sy].push_back({sx,d});
    }
    Dijsktra();
    PrintPath(D);
    cout<<"\n";
    cout<<Rc[D]<<" "<<dis[D]<<" "<<totalPeo[D]<<endl;
    return 0;
}