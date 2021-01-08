#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
using pii = pair<int,int>;
int N,M,C1,C2;
vector<vector<pii> > G;
vector<int> team;
vector<int> dis;
vector<int> Rc;
vector<int> totalTeam;
void Dijkstra(){
    dis = vector<int>(N,0x3f3f3f3f);

    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,C1});

    Rc[C1] = 1;
    dis[C1] = 0;

    totalTeam[C1] = team[C1];

    while(!pq.empty()){

        auto v = pq.top();
        pq.pop();

        int x = v.second;
        if(v.first > dis[x])
            continue;

        for(auto &e : G[x]){

            if(dis[e.first]  > dis[x] + e.second){

                Rc[e.first] = Rc[x];

                dis[e.first] = dis[x] + e.second;

                totalTeam[e.first] = totalTeam[x] + team[e.first];

                pq.push({dis[e.first] , e.first});
            }else if(dis[e.first] == dis[x] + e.second){
                Rc[e.first] += Rc[x];

                if(totalTeam[e.first] < totalTeam[x] + team[e.first]){
                    
                    totalTeam[e.first] = totalTeam[x] + team[e.first];
                }
            }
        }
    }
}
int main()
{
    cin>>N>>M>>C1>>C2;

    G.resize(N);
    team.resize(N);
    Rc.resize(N);
    totalTeam.resize(N);

    for(int i = 0;i < N;++i)
    {
        cin>>team[i];
    }
    for(int i = 0;i < M;++i){
        int x,y,z;
        cin>>x>>y>>z;
        G[x].push_back({y,z});
        G[y].push_back({x,z});
    }
    Dijkstra();
    cout<<Rc[C2]<<" "<<totalTeam[C2]<<endl;
    return 0;
}