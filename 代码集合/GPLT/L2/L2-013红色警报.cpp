#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > G;
vector<bool> visited,flag;
int N,M,K;
vector<int> preNext;
void dfs(int x){
    visited[x] = true;
    for(auto w : G[x]){
        if(!visited[w] && !flag[w]){
            dfs(w);
        }
    }
}
int ansCit(){
    int ans = 0;
    fill(visited.begin(),visited.end(),false);
    for(int i = 0;i < N;++i)
    {
        if(!visited[i] && !flag[i])
        {
            dfs(i);
            ++ans;
        }
    }
    return ans;
}
int main()
{
    cin>>N>>M;
    visited = vector<bool>(N,false);
    flag = vector<bool>(N,false);
    G.resize(N);
    for(int i = 0;i < M;++i){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cin>>K;
    int preNum = ansCit();
    preNext.push_back(preNum);
    
    for(int i = 1;i <= K;++i){
        int x;
        cin>>x;
        flag[x] = true;
        int y = ansCit();
        if(y  > preNext.back()){
            cout<<"Red Alert: City "<<x<<" is lost!\n";
        }else{
            cout<<"City "<<x<<" is lost."<<endl;
        }

        preNext.push_back(y);
        if(i == N)
        {
            cout<<"Game Over."<<endl;
        }
    }


    return 0;
}