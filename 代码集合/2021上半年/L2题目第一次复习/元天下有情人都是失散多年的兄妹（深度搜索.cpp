#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
vector<int> ves[100100];
//vector<char> sex;
char sex[100100];
//vector<bool> visited;
bool visited[100100];
int flag ;
int a,b;
void dfs(int n,int  num){
    if(num > 4){
        return ;
    }

    visited[n] = true;
    for(auto w : ves[n]){
        if(!visited[w]){
            visited[w] = true;
            dfs(w,num+1);
        }else{
            flag = 1;
        }
    }
}
int main(){
    int N;
    cin>>N;
    //ves.resize(100100);
    for(int i = 0;i < N;i++){
        char c;
        int peo,father,mather;
        cin>>peo>>c>>father>>mather;
        sex[peo] = c;

        if(father != -1){
            ves[peo].push_back(father);
            sex[father] = 'M';
        }
        if(mather != -1){
            ves[peo].push_back(mather);
            sex[mather] = 'F';
        }
    }
    int M;
    cin>>M;

    for(int i = 0;i < M;i++){

        memset(visited,false,sizeof(visited));
       // fill(visited.begin(),visited.end(),false);
        //int a,b;
        cin>>a>>b;
        if(sex[a] == sex[b]){
            cout<<"Never Mind"<<endl;
            continue;
        }
        flag = 0;
        dfs(a,1);
        dfs(b,1);
        if(!flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
