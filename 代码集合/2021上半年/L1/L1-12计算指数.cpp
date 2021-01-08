#include<iostream>
using namespace std;
int main()
{
    int n,sum = 1;
    cin>>n;
    int ans = n;
    while(ans--)
    {
        sum *= 2;
    }
    cout<<"2^"<<n<<" = "<<sum<<endl;
    return 0;
}