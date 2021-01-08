#include<iostream>
#include<random>
#include<chrono>
#include<map>

using namespace std;
int main(){
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937  gen(seed);
    //均匀分布0.....1000000
    uniform_int_distribution<> dis(0,1000000);
    map<int,int> mp;
    for(int i = 0;i < 1000;++i){
        cout<<dis(gen)<<" ";
    }
    cout<<endl;

    return 0;
}