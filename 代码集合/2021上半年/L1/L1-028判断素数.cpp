#include<iostream>
#include<cmath>
using namespace std;
bool Valid(int  x)
{
    if(x == 1)
        return false;
    for(int i = 2;i <= sqrt(x);++i)
        if(x%i == 0)
            return false;
    return true;
}
int main()
{
    int N;
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        int num;
        cin>>num;
        cout<<(Valid(num) ? "Yes\n" : "No\n");
    }
    return 0;
}