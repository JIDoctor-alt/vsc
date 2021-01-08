#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main(){
    int N;
    cin>>N;
    vector<int> num;
    num.resize(N);
    int sum = 0;
    for(int i = 0;i < N;i++){
         cin>>num[i];
         sum += num[i];
    }
       
    sort(num.begin(),num.end());
    int n1 = N/2;
    int sum1 = 0;
    for(int i = 0;i < n1;i++){
        sum1 += num[i];
    }

    cout<<"Outgoing #: "<<(N-n1)<<endl;
    cout<<"Introverted #: "<<n1<<endl;
    cout<<"Diff = "<<(sum - sum1 - sum1)<<endl;


    return 0;
}