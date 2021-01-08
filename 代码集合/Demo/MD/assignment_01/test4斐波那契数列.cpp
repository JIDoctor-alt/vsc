#include<iostream>
#include<algorithm>
using namespace std;
long long n;
long long f(long long x)
{
    if(x == 0)
        return 0;
    if(x == 1)
        return 1;
    return f(x-1) + f(x-2);
}
long long dt()
{
    long long constant = 1000000007;
    int first = 0;
    int second = 1;
    while(n-- > 0)
    {
        int temp = first + second;
        first = second % constant;
        second = temp % constant;
    }
    return first;
}
int main()
{
    cin>>n;
    cout<<"递归实现\n";
    cout<<(f(n)%1000000007)<<endl;
    cout<<"递推实现\n";
    cout<<dt()<<endl;
    return 0;
}