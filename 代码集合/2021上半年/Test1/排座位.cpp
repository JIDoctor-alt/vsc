#include<iostream>

using namespace std;
int connect[110][110] = {0};
int pre[110];
int find(int c){
    return pre[c] == c ? c : find(pre[c]);
}
void un(int x,int y){
    int nx = find(x);
    int ny = find(y);
    if(pre[nx]!=ny){
        pre[nx] = ny;
    }
}
int main(){
    int N,M,K;
    cin>>N>>M>>K;

    for(int i = 0;i <= N;i++){
        pre[i] = i;
    }


    for(int i = 0;i < M;i++){

        int a,b,z;

        cin>>a>>b>>z;

        if(z == -1)
          connect[a][b] = connect[b][a] = 1;
        else
            un(a,b);
    }

    for(int i = 0;i < K;i++){
        int x_1,y_1;
        cin>>x_1>>y_1;
        if((find(x_1) == find(y_1)) && !connect[x_1][y_1]){
            cout<<"No problem"<<endl;
            continue;
        }
        if((find(x_1) != find(y_1))&& !connect[x_1][y_1]){
            cout<<"OK"<<endl;
            continue;
        }
        if((find(x_1) == find(y_1)) && connect[x_1][y_1]){
            cout<<"OK but..."<<endl;
            continue;
        }
        if((find(x_1)!= find(y_1)) && connect[x_1][y_1]){
            cout<<"No way"<<endl;
            continue;
        }
    }
    return 0;
}