#include<iostream>

using namespace std;
int fun(int num)
{
    if(num == 0 || num == 1 )
        return 1;
    else return fun(num-1)+fun(num-2);
}
int main()
{
    int n;
    while (cin>>n)
    {
        cout<<fun(n)<<endl;
    }
    
    return 0;
}