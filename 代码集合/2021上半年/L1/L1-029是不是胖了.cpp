#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double H,W;
    cin>>H;
    W = (H - 100)*0.9*2;
    cout<<fixed<<setprecision(1)<<W<<endl;
    return 0;
}