#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<vector<int> > ves;
    ves.resize(N+1);
    int root ;
    for(int i = 1;i <= N;i++){
        int num;
        cin>>num;
        if(num == -1)
            root = i;
        else{
            ves[num].push_back(i);//i的儿子结点
        }
    }
    vector<int> level(100100,0);

    queue<int> pq;
    level[root] = 1;//
    pq.push(root);
    //int maxIndex = root;
    int maxDeep = 1;
    vector<int> result;
    while(!pq.empty()){
        int v = pq.front();
        pq.pop();

        for(auto i : ves[v]){

            level[i] = level[v] + 1;

            if(level[i] > maxDeep){
                maxDeep =  level[i]; 
            }
            pq.push(i);
        }

    }
    cout<<maxDeep<<endl;
   // sort(result.begin(),result.end());
    int flag = 0;
   // int le = result.size();
    for(int i = 1;i <= N ;i++){
        
        if(level[i] == maxDeep){
            if(flag)cout<<" ";
            cout<<i;
            flag = 1;
        }
        
    }

    return 0;
}