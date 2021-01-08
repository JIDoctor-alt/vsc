#include<iostream>

using namespace std;
int fun(int n){
    
    if(n == 1)return 2;
    return 2 * fun(n-1);
}
int main(){
    int N;
    cin>>N;
    cout<<2<<"^"<<N<<" = "<<fun(N);
    return 0;
}