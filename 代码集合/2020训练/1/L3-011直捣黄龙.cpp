#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
using pii = pair<int,int>;
struct edge
{
    int to,le;
};
vector<vector<edge> > g;
vector<int> dis;
vector<int> numpeo,totalNum;
vector<int> Rc,pre;
int N,K,S,D;
string a,b;
map<string,int> msindex;
map<int,string> sname;
vector<int> deal;
void Dijsktra()
{
    dis = vector<int>(N,0x3f3f3f3f);

    pre = vector<int>(N,-1);

    priority_queue<pii,vector<pii>,greater<pii> > pq;
    
    Rc[S] = 1;
    totalNum[S] = numpeo[S];
    
    dis[S] = 0;
    pre[S] = -1;
    deal[S] = 0;
    pq.push({0,S});

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
                deal[e.to] = deal[x] + 1;
                totalNum[e.to] = totalNum[x] + numpeo[e.to];
                dis[e.to] = dis[x] + e.le;
                pre[e.to] = x;

                pq.push({dis[e.to],e.to});
            }
            else if(dis[e.to] == dis[x] + e.le)
            {
                Rc[e.to] += Rc[x];

                if(deal[e.to] < deal[x] + 1 || (deal[e.to] == deal[x] + 1)&&totalNum[e.to] < totalNum[x] + numpeo[e.to])
                {
                    deal[e.to] = deal[x] + 1;

                    totalNum[e.to] = totalNum[x] + numpeo[e.to];
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
        cout<<sname[x];
        return;
    }
    printPath(pre[x]);
    cout<<"->"<<sname[x];
}
int main()
{
    cin>>N>>K>>a>>b;

    g.resize(N);
    numpeo.resize(N);
    Rc.resize(N);
    totalNum.resize(N);
    deal.resize(N);
  //  pre.resize(N);
    //己方大本营
    msindex[a] = 0;
    sname[0] = a;

    S = msindex[a];

    for(int i = 1;i < N;++i)
    {
        string xid;
        int num;
        cin>>xid>>num;

        msindex[xid] = i;
        sname[i] = xid;

        numpeo[i] = num;
    }

    D = msindex[b];
     
    for(int i = 0;i < K;++i)
    {
        string x,y;
        int len;
        cin>>x>>y>>len;
        int nx = msindex[x], ny = msindex[y];
        g[nx].push_back({ny,len});
        g[ny].push_back({nx,len});
    }

    Dijsktra();
    printPath(D);
    cout<<endl;
    cout<<Rc[D]<<" "<<dis[D]<<" "<<totalNum[D]<<endl;
    return 0;
}
