#include<iostream>
#include<vector>
#include<functional>
#include<utility>
#include<map>
#include<string>
#include<queue>

using namespace std;
using pii = pair<int,int>;

struct edge{
    int to;
    int cost;
};
int N,K;
string S,D;
///边
vector< vector<edge> > G;
//城市又有多少dijun
vector<int> Cout;
vector<int> totalCout;//总共歼灭多少敌军
//最短路径
vector<int> dis;
//有多少条路径
vector<int> RC;

//存储路径的父结点
vector<int> path;

//存取对应城市的编号
map<string,int> ci;
vector<int> city_break;
vector<int> jiefang_city;
vector<string> cit;
int scity,ecity;
void Disktra(){
    priority_queue<pii,vector<pii>,greater<pii> > pq;;

    dis[scity] = 0;
    RC[scity] = 1;

    jiefang_city[scity] = 0;//到自己没有边

    path[scity] = -1;
    //大本营的敌军数量为0
    totalCout[scity] = Cout[scity];

   

    pq.push({0,scity});

    while(!pq.empty()){

    	auto x = pq.top();

    	pq.pop();
        
    	int v  = x.second;

    	if(dis[v] < x.first)
    		continue;


    	for(auto w : G[v]){

    		if(dis[v] + w.cost < dis[w.to]){

    			dis[w.to] = w.cost + dis[v];
                RC[w.to] = RC[v]; 
                //解放了多少城市边数加1
                jiefang_city[w.to] = jiefang_city[v] + 1;
                
                totalCout[w.to] = totalCout[v] + Cout[w.to];
    			path[w.to] = v;

    			
    			
    			pq.push({dis[w.to],w.to});

    		}else if(dis[v] + w.cost == dis[w.to]){

    			RC[w.to] += RC[v];


                if(jiefang_city[w.to] < jiefang_city[v] + 1){

                    jiefang_city[w.to] = jiefang_city[v] + 1;
                    totalCout[w.to] = totalCout[v] + Cout[w.to];

                    path[w.to] = v;
                }else if(jiefang_city[w.to] = jiefang_city[v] + 1){
                    
                    if(totalCout[w.to] < totalCout[v] + Cout[w.to]){
                         path[w.to] = v;


    				     totalCout[w.to] = totalCout[v] + Cout[w.to];
    				
    			  }
                }

                 
    		}
    	}
    }
}

void Print(int x){
    if(x == scity){
        cout<<cit[x];
        return ;
    }
    Print(path[x]);
    cout<<"->"<<cit[x];
}
int main(){
    cin>>N>>K>>S>>D;

    dis = vector<int>(N,0x3f3f3f3f);

    
    
    jiefang_city = vector<int>(N,0);


    G.resize(N);
    Cout.resize(N);
    RC.resize(N);
    path.resize(N);
    
    totalCout.resize(N);
    
    cit.resize(N);
    ///大本营对应的编号为0
    ci[S] = 0;
    //
    cit[0] = S;
    //大本营的敌军数量为0
    Cout[0] = 0;

    for(int i = 1;i < N;i++){
        string c;
        //int num;
        cin>>c>>Cout[i];//城市的名字和城市敌人数量

        ci[c] = i;//城市对应的编号
        cit[i] = c;//编号对应的城市
       
       // Cout[i] = num;///该城市有这些敌军
    }

    scity = ci[S];//起点的城市编号
    ecity = ci[D];//终点的城市编号

    //K条边
    for(int i = 0;i < K;i++){

        string s,e;//两个城市 的名字
        int len;//距离

        cin>>s>>e>>len;

        int ssi = ci[s];//这个城市的编号
        int eei = ci[e];

        //每个城市的邻接点  距离
        G[ssi].push_back({eei,len});
        G[eei].push_back({ssi,len});

    }

    Disktra();
    Print(ecity);
    cout<<endl;

    cout<<RC[ecity]<<" "<<dis[ecity]<<" "<<totalCout[ecity]<<endl;
}