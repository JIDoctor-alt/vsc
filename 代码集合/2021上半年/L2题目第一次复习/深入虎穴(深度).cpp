#include<iostream>
#include<vector>

using namespace std;

int maxInex,maxDeep = -1;
//int ans = 0;

vector<int> pre(100010,-1);//,deep(100010,0);
vector<vector<int> > ves;
int N,K;
void dfs(int v,int ans){

    if(ans > maxDeep){
            maxDeep = ans;
            maxInex = v;
        }
    if(ves[v].size())
    for(auto w : ves[v]){

       
        
        dfs(w,ans+1);
    }
}
int main(){
    cin>>N;
    ves.resize(N+1);
   

    for(int i = 1;i <= N;i++){

        cin>>K;

        if(K == 0)continue;

        for(int j = 0;j < K;j++){
            int num;
            cin>>num;
            ves[i].push_back(num);
            pre[num] = i;
        }
    }
    int i;
    for( i = 1;i <= N;i++){
        if(pre[i] == -1)
            break;
    }
    
    
    //deep[i] = 0;
    maxInex = i;
    maxDeep = 0;
    if(ves[i].size())
    dfs(i,0);
    cout<<maxInex<<endl;
    return 0;
}