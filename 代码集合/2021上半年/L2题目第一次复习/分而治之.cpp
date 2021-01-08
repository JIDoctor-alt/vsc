#include<iostream>
#include<vector>

using namespace std;
int main(){
    int N,M;
    cin>>N>>M;

    vector<vector<int> > ves;

    ves.resize(N+1);

    vector<int> Indgree;
    Indgree.resize(N+1);
    //
    for(int i = 0;i < M;i++){
        int a,b;
        cin>>a>>b;
        ves[a].push_back(b);
        ves[b].push_back(a);
        Indgree[a]++;
        Indgree[b]++;
    }
    int K;
    cin>>K;
    vector<int> des;
    des.resize(N+1);

    for(int i = 0;i < K;i++){
        int num;
        cin>>num;//这些城市

        for(int d = 1;d<= N;d++)
                des[d] = Indgree[d];

        for(int j = 0;j < num;j++){
            int id;
            cin>>id;
            if(des[id])
                 des[id] = 0;

            for(auto w : ves[id])
                if(des[w]) 
                     des[w] --;
        }
        int flag = 0;
        for(int k = 1;k <= N;k++){
            if(des[k]){//如果存在失败的
                flag = 1;
                break;
            }
        }
        if(flag)
            cout<<"NO"<<endl;
        else 
            cout<<"YES"<<endl;

    }
    return 0;
}