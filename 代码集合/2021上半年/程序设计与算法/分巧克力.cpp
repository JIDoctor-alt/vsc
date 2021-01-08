#include<iostream>
#define EPS 1e-7
using namespace std;
int N,M;
int H[100100],W[100100];
bool Valid(int s)
{
    int ans = 0;
    for(int i = 0;i <  N;i++)
    {
        ans += (H[i]/s)*(W[i]/s);
    }
    return ans >= M;
}
int main(){
    ios::sync_with_stdio(false);
    
    cin>>N>>M;
    for(int i = 0;i < N;i++)
    {
        cin>>H[i]>>W[i];
    }
    int l = 1,r = 100000;
    while(r - l > EPS )
    {
        int mid = (r + l)/2;
        if(Valid(mid)){
            l = mid + 1 ;
        }else{
            r = mid ;
        }
        //cout<<l<<" "<<r<<endl;
    }
    cout<<l-1<<endl;
    return 0;
}