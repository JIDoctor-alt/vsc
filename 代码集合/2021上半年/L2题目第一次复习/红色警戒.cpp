#include<iostream>
#include<cstring>

using namespace std;
int connect[510][510];
int visited[510];
int N,M;
void dfs(int s){
    for(int i = 0;i < N;i++){
        if(connect[s][i] && !visited[i]){
            visited[i] = 1;
            dfs(i);
        }
    }
}
int countArea(){
    memset(visited,0,sizeof(visited));
    int ans = 0;
    for(int i = 0;i < N;i++){
        if(!visited[i]){
            visited[i] = 1;
            dfs(i);
            ans++;
        }
    }
    return ans;
}
int main(){
    cin>>N>>M;
    memset(connect,0,sizeof(connect));
    for(int i = 0;i < M;i++){
        int a,b;
        cin>>a>>b;
        connect[a][b] = connect[b][a] = 1;
    }
    int K;
    cin>>K;
    int c = countArea();
    for(int i = 0;i < K;i++){
        int num;
        cin>>num;

        for(int j = 0;j < N;j++){

            if(connect[num][j]){

                connect[num][j] = connect[j][num] = 0;
            }
        }

        int break_city = countArea();

     /*   if(c+1 < break_city){
            cout<<"Red Alert: City "<<num<<" is lost!"<<endl;
        }else{
             cout<<"City "<<num<<" is lost."<<endl;
           
        }*/

        if(c+1 == break_city || (c == break_city)){
             cout<<"City "<<num<<" is lost."<<endl;
        }else{
           
              cout<<"Red Alert: City "<<num<<" is lost!"<<endl;
           
        }
        
        
        c = break_city;
        if(i == N-1)
            cout<<"Game Over."<<endl;

    }
}