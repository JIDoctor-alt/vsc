#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{
    double h,w;
    cin>>w>>h;
    double flag = w /(h*h);
    cout<<fixed<<setprecision(1)<<flag<<endl;
    if(flag > 25)
    {
        cout<<"PANG"<<endl;
    }
    else 
    {
       cout<<"Hai Xing"<<endl; 
    }
    return 0;
}