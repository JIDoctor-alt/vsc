#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
vector<vector<int> > ves;
int N,K;
  int maxDeep = -1;//最大深度初始值
//vector<bool> visitd;
vector<int> deep;

int maxIndex = -1;
vector<int> pre(100010,-1);
//编号从1开始，1也可能不是入口
//广搜 求深度
void bfs(int o){

    queue<int> pq;

        pq.push(o);
       // visitd[o] = true;
        deep[o] = 1;
        maxIndex = o;
        while(!pq.empty()){

            int v = pq.front();
            pq.pop();

           

            int l  = ves[v].size();          
            if(l)
            for(auto w : ves[v]){
                 deep[w] = deep[v] + 1;
            if(deep[w] > maxDeep){

                maxDeep = deep[w];
                maxIndex = w;
            }
          //if(!visitd[w]){
          // visitd[w] = true;
          pq.push(w);

              //  }
            }

        }
}
int main(){
    cin>>N;
    
    ves.resize(N+1);
    //visitd.resize(N+1);
    deep.resize(N+1);

    for(int i = 1; i<= N;i++){
        cin>>K;
        if(K==0)continue;
        for(int j = 0;j < K;j++){//K个门
            int num;
            cin>>num;
            ves[i].push_back(num);
            pre[num] = i;
        }
    }
    int i;
    for( i = 1;i <= N;i++)
    {
        if(pre[i] == -1){
            break;
        }
    }
    bfs(i);
   
    cout<<maxIndex<<endl;
    return 0;
}