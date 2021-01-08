#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int sum = a * b;
    int res = 0;
    while(sum)
    {
        res = res * 10 + sum % 10;
        sum/= 10;
    }
    cout<<res;
    return 0;
}