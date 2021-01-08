#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int xum = abs(c-a) + abs(d - b);
    cout<<xum<<endl;
    return 0;
}