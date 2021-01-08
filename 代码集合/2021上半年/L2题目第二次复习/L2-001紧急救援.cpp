#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using pii = pair<int,int>;
vector<vector<pii> > G;
int N,M,S,D;
vector<int> dis;
vector<int> totalCount;
vector<int> Count;
vector<int> Cnt;
vector<int> pre;
void printPath(int x)
{
    if(x == S)
    {
        cout<<x;
        return;
    }
    printPath(pre[x]);
    cout<<" "<<x;
}
void Dijkstra()
{
    fill(dis.begin(),dis.end(),0x3f3f3f3f);
    dis[S] = 0;  
    Cnt[S] = 1;
    totalCount[S] = Count[S];
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({dis[S],S});
    while(!pq.empty())
    {
        auto v = pq.top();
        pq.pop();

        int x = v.second, y = v.first;

        if(y > dis[x])
            continue;

        for(auto w : G[x])
        {
            int c = w.first, l = w.second;
            if(dis[c] > dis[x] + l)
            {
                dis[c] = dis[x] + l;
                pre[c] = x;

                totalCount[c] = Count[c] + totalCount[x];
                Cnt[c] = Cnt[x];

                pq.push({dis[c],c});
            }
            else if(dis[c] == dis[x] + l)
            {
                Cnt[c] += Cnt[x];
                if(totalCount[c] < totalCount[x] + Count[c])
                {
                    pre[c] = x;
                    totalCount[c] = totalCount[x] + Count[c];
                }
            }
        }
    }
}
int main()
{
    cin>>N>>M>>S>>D;
    G.resize(N);
    pre.resize(N);
    Cnt.resize(N);
    dis.resize(N);
    totalCount.resize(N);
    Count.resize(N);
    for(int i = 0;i < N;++i)
    {
        cin>>Count[i];
    }
    for(int i = 0;i < M;++i)
    {
        int x,y,c;
        cin>>x>>y>>c;
        G[x].push_back({y,c});
        G[y].push_back({x,c});
    }
    Dijkstra();
    cout<<Cnt[D]<<" "<<totalCount[D]<<endl;
    printPath(D);
    return 0;
}