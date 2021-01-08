#include<iostream>
using namespace std;
void fun(int x,int ans)
{
    if(x == 1)
    {
        cout<<ans;
        return;
    }
    if(x%2 == 0)
    {
        x /= 2;
    }
    else 
    {
        x = (3*x + 1)/2;
    }
    fun(x,ans+1);
}
int main()
{
    int n;
    cin>>n;
    fun(n,0);
    return 0;
}