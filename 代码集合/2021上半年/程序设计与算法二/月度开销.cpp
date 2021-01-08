#include<iostream>
#define EPS 1e-6
using namespace std;
const int MAX = 100100;
int M,N;
int Day[MAX];
bool Valid(int s){
    int cnt = 1;
    int total = 0;

    for(int i = 0;i < N;i++){

        if(s < Day[i])return false;

        if(total + Day[i] > s){
            total = Day[i];
            cnt++;
        }else{
            total += Day[i];
        }
    }
    return cnt <= M;
}
int main(){
    cin>>N>>M;
    for(int i = 0;i < N;i++){
        cin>>Day[i];
    }
    //每天的
    int l = 0,r = 1<<30;
    while(r - l > EPS){

       // int mid = l + (r - l)/2;
       int mid = (l+r)/2;
        if(Valid(mid)){
           ///  l = mid + 1;
           r = mid ;
        }else{
            l = mid + 1;

        }
    }
    cout<<l;
    return 0;
}