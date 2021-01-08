#include<iostream>
#include<numeric>
#include<iomanip>
using namespace std;
int main()
{
    double price,countT;
    cin>>price>>countT;
    cout<<fixed<<setprecision(2)<<(price*countT*0.1);
    return 0;
}