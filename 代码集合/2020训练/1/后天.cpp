#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int d;
    cin>>d;
    d = ((d + 2)% 7 ? (d + 2)% 7 : 7);
    cout<<d;
    return 0;
}