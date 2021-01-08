#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using pii = pair<int,int>;
vector<vector<pii> > G;
vector<int> Count;
vector<int> dis;
vector<int> totalCount;
vector<int> Rc;
vector<int> totalRc;
vector<int> pre;
int N,M,S,D;
void Dijkstral()
{
    fill(dis.begin(),dis.end(),0x3f3f3f3f);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    Rc[S] = 1;
    totalCount[S] = Count[S];
    dis[S] = 0;
    pq.push({0,S});
    pre[S] = -1;
    while(!pq.empty())
    {
        auto v = pq.top();
        pq.pop();
        
        int x = v.second;
        if(dis[x] < v.first)
            continue;
        
        for(auto w : G[x])
        {
            int to = w.first, le = w.second;
            if(dis[to] > dis[x] + le)
            {
                pre[to] = x;
                dis[to] = dis[x] + le;
                Rc[to] = Rc[x];
                totalCount[to] = totalCount[x] + Count[to];

                pq.push({dis[to],to});
            }
            else if(dis[to] == dis[x] + le)
            {
                Rc[to] += Rc[x];
                if(totalCount[to] < totalCount[x] + Count[to])
                {
                     pre[to] = x;
                     totalCount[to] = totalCount[x] + Count[to];
                }
               
            }
        }
    }
}
void printPath(int x)
{
    if(x == S)
    {
        cout<<S;
        return;
    }
    printPath(pre[x]);
    cout<<" "<<x;
}
int main()
{
    cin>>N>>M>>S>>D;
    G.resize(N);
    Count.resize(N);
    dis.resize(N);
    totalCount.resize(N);
    Rc.resize(N);
    totalRc.resize(N);
    pre.resize(N);
    for(int i = 0;i < N;++i)
        cin>>Count[i];
    for(int i = 0;i < M;++i)
    {
        int x,y,z;
        cin>>x>>y>>z;
        G[x].push_back({y,z});
        G[y].push_back({x,z});
    }
    Dijkstral();
    cout<<Rc[D]<<" "<<totalCount[D]<<endl;
    printPath(D);
    return 0;

}