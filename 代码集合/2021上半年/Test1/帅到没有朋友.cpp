#include<iostream>
#include<vector>

using namespace std;
int pe[100100] = {0};
int visited[100100] = {0};//已经加入
int main(){
    int N;
    cin>>N;
    for(int i = 0;i < N;i++){
        int K;
        cin>>K;
        
        for(int j = 0;j < K;j++){
            int id;
            cin>>id;
            if(K!=1)
                pe[id]=1;
        }
    }
    int M;
    cin>>M;
    vector<int> peopleS;
    for(int i = 0;i < M;i++){
        int test_id;
        cin>>test_id;
        if(pe[test_id] == 0 && !visited[test_id]){
            peopleS.push_back(test_id);
            visited[test_id] = 1;
        }

    }
    int len = peopleS.size();
    if(len == 0)
        cout<<"No one is handsome"<<endl;
    else{
        for(int i = 0;i < len;i++){
            int t_id = peopleS[i];
            if(i!=0)
            cout<<" ";
            printf("%05d",t_id);
        }
    }
    return 0;
}