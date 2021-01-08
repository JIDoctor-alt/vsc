#include<iostream>

using namespace std;
bool Valid(int n){
    int ans = 0;
    while (n)
    {
        ans += (n&1);
        n >>=1;
    }
    if(ans > 32)return false;
    return true;
    
}
int fun(int s){
    if(s == 1)return 1;
    return s*fun(s-1);
}
int sum(int d){
    if(d == 1)return 1;
    return fun(d) + sum(d-1);
}
int main(){
    signed int N;
    cin>>N;
  
    if(Valid(N)){
        cout<<sum(N)<<endl;
    }
   
    return 0;
}