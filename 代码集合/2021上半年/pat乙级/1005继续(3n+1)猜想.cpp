#include<iostream>
#include<set>
#include<vector>
#include<numeric>
using namespace std;
const int MAX_N = 110;
int pre[MAX_N];
void fun(int x)
{
    if(x == 1)
        return;
    if( x % 2 == 0)
    {  
       pre[x/2] = x;
       fun(x/2);
    }    
    else
    {
       pre[x/2] = x;
       fun(3*x + 1);
    } 
}
int main()
{
    iota(pre,pre + MAX_N,0);
    set<int> st;
    int N;
    cin>>N;
    vector<int> ves;
    for(int i = 0;i < N;++i)
    {
        int num;
        cin>>num;
        ves.push_back(num);
    }

    return 0;
}