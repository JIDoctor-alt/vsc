#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double price,d;
    cin>>price>>d;
    d = d * 0.1;
    cout<<fixed<<setprecision(2)<<(price * d)<<endl;
    return 0;
}