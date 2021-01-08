#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct edge
{
    int a,b,c,d;
};
int main()
{
    int N,pa = 0,pb = 0;
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        int x,y,z,w;
        cin>>x>>y>>z>>w;
        int fa = x + z;
        if(y == fa && w != fa)
        {
            ++pb;
        }
        if(w == fa && y != fa)
        {
            ++pa;
        }
    }
    cout<<pa<<" "<<pb<<endl;
    return 0;
}