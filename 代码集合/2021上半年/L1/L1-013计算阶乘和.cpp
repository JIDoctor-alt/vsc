#include<iostream>
using namespace std;
int N,S;
int fun(int x)
{
    if(x == 1)
        return 1;
    return x*fun(x-1);
}
int judge(int x)
{
    if(x == 1)
        return 1;
    return fun(x)+judge(x-1);
}
int main()
{
    cin>>N;
    cout<<judge(N)<<endl;
    return 0;
}