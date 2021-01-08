#include<iostream>
#include<vector>

using namespace std;
int main(){
    int AN,BN;
    cin>>AN;
    vector<int> A,B;
    A = vector(AN+1,0);
    for(int i = 0;i <= AN;i++)
    {
        int e,c;
        cin>>e>>c;
        A[e] = c;//
    }
    cin>>BN;
    B = vector(BN+1,0);
    for(int i = 0;i <= BN;i++)
    {
        int e,c;
        cin>>e>>c;
        B[e] = c;
    }
    for(int i = AN;i>=0;i--){
        
    }


    return 0;
}