#include<iostream>
using namespace std;
int fun(int x)
{
    if(x == 1)
        return 1;
    return fun(x-1)*x;
}
int main()
{
    int N;
    cin>>N;
    int sum = 0;
    for(int i = 1;i <= N;++i)
    {
        sum += fun(i);
    }
    cout<<sum<<endl;
    return 0;
}