#include<iostream>

using namespace std;
int main(){
    int N;
    cin>>N;
    int ji = 0,ou = 0;
    for(int i = 0;i < N;i++){
        int num;
        cin>>num;
        if(num%2){
            ji++;
        }else{
            ou++;
        }
    }
    cout<<ji<<" "<<ou<<endl;
    return 0;
}