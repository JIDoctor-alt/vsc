#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        double h,w;
        cin>>h>>w;
        double sw = (h-100)*0.9*2;
        if(abs(w - sw) < sw*0.1)
        {
            cout<<"You are wan mei!"<<endl;
        }
        else if(w < sw)
        {
            cout<<"You are tai shou le!"<<endl;
        }
        else 
        {
            cout<<"You are tai pang le!"<<endl;
        }
    }
    return 0;
}