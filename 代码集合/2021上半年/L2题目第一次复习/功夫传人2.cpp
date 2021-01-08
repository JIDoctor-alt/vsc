#include<iostream>
#include<vector>

using namespace std;
vector<bool> visited;
vector<vector<int> > ves;
vector<int> flag;
double result = 0,r; 
void dfs(int v,double deep){
    
    if(flag[v] == 1){
        //得道者
        int t = ves[v][0];
        result += t*deep*1.0;
        return;
    }

    for(auto w : ves[v]){
        if(!visited[w]){
            visited[w] = true;
            dfs(w,deep*(1-r/100));
        }
    }
}
int main(){
    int N;
    double z;
    cin>>N>>z>>r;
    ves.resize(N);
    visited.resize(N);
    flag = vector<int>(N,0);//0表示不是得道者
    for(int i = 0;i < N;i++){
        int  num;
        cin>>num;
        if(num == 0){
            flag[i] = 1;//得到者
            int Multipe;
            cin>>Multipe;
            ves[i].push_back(Multipe);
        }else{

            for(int j = 0;j < num;j++){
                int id;
                cin>>id;
                ves[i].push_back(id);
            }
        }
    }
    visited[0] = true;
    dfs(0,z);
    cout<<(int)result<<endl;
    return 0;
}