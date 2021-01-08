#include<iostream>
using namespace std;
int main()
{
    int d;
    cin>>d;
    int x = (d + 2) % 7;
    if(x == 0)
        x = 7;
    cout<<x;
    return 0;
}