#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(b < 0)
    {
        cout<<a<<"/("<<b<<")=";
        cout<<fixed<<setprecision(2)<<a/(b*1.0)<<endl;
    }
    else if(b > 0)
    {
        cout<<a<<"/"<<b<<"=";
        cout<<fixed<<setprecision(2)<<a/(b*1.0)<<endl;
    }
    else if(b == 0)
    {
        cout<<a<<"/"<<b<<"=Error"<<endl;
    }
    return 0;
}