#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;


int visited[10010];
int connect[10010][10010];
int ves[10010];//存取该顶点所能传到的地方
int N,M,K;
int ans ;
int max_len,min_id ;
vector< vector<int>> G;
void bfs(int v){

    queue<int> pq;
    visited[v] = 1;

    pq.push(v);//根结点入队

    while(!pq.empty()){

        int x = pq.front();
        pq.pop();
        
        ans++;
        for(auto w : G[x]){
            if(!visited[w]){
                visited[w] = 1;

                if(max_len < ans){
                    max_len = ans;
                    min_id = w;
                }else if(max_len == ans){
                    if(min_id > w){
                        min_id = w;
                    }
                }
                pq.push(w);
            }
        }
        /*for(int i = 1;i <= N;i++){
            if(!visited[i] && connect[x][i]){

                visited[i] = 1;

                
                if(max_len < ans){
                    max_len = ans;
                    min_id = i;
                }else if(max_len == ans){
                    if(min_id > i){
                        min_id = i;
                    }
                }

                pq.push(i);
            }
        }*/
    }
}
int main(){

    
    cin>>N>>M>>K;
   
    G.resize(N+1);
    for(int i = 0;i < M;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        //connect[a][b] = connect[b][a] = 1;
    }
    for(int i = 1;i <= N;i++){
        
        ans = 0;
        max_len = 0;//最长的距离
        min_id = 1<<30;///最小的下标

        memset(visited,0,sizeof(visited));
        bfs(i);
        //得到每一个点的最深处
        ves[i] = min_id;
        
    }
    for(int i = 0;i < K;i++){
        int test_num;
        cin>>test_num;
        if(ves[test_num] == 1<<30)
            cout<<"0"<<endl;
        else 
            cout<<ves[test_num]<<endl;
    }

    return 0;
}