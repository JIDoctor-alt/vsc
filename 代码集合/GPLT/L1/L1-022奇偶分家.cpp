#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int x = 0, y = 0;
    for(int i = 0;i < N;++i){
        int id;
        cin>>id;
        if(id % 2 == 0)
            ++x;
        else 
            ++y;
    }
    cout<<y<<" "<<x<<endl;
    return 0;
}