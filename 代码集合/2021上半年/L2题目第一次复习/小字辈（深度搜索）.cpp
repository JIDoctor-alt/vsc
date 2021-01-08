#include<iostream>
#include<vector>

using namespace std;
vector<vector<int> >ves;
vector<int> level;
int maxDeep = 1;
void dfs(int s,int deep){
    if(deep > maxDeep){
            maxDeep = deep;
    }
    for(auto w : ves[s]){
        level[w] = deep + 1;
        
        dfs(w,deep+1);
    }
}
int main(){
    int N;
    cin>>N;
    int root;
    level = vector<int>(N+1,0);
    ves.resize(N+1);
    for(int i = 1;i <= N;i++){
        int num;
        cin>>num;
        if(num == -1){
            root = i;
        }else{
            ves[num].push_back(i);
        }
    }
    level[root] = 1;
    dfs(root,1);
    cout<<maxDeep<<endl;
    int flag = 0;
    for(int i = 1;i <= N;i++){
        if(level[i] == maxDeep){
                if(flag)
                    cout<<" ";
                cout<<i;
                flag = 1;
        }
    }
    return 0;
}