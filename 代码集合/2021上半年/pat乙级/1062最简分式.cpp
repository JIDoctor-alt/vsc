#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
using pii = pair<int,int>;
int judge(int a,int b)
{
    if(a < b)
    {
        swap(a,b);
    }
    while(b)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return b == 0 ? a : -1;
}
int main()
{
    vector<pii> res;
    int n1,n2,m1,m2,K;
    scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&K);
    int x1 = n1 * m2, x2 = n2 * m1;
    int y = m1 * m2;
    for(int i = x1; i <= x2;++i)
    {
        int d = judge(i,y);
        if(d != -1)
        {
            int ny = y/d;
            int nx = i/d;
            if(ny == K)
            {
                res.push_back({nx,ny});
            }
        }
        else 
        {
            if(y == K)
            {
                res.push_back({i,y});
            }
        }
    }
    int ans = 0;
    for(auto w : res)
    {
        ++ans;
        if(ans != 1)
        {    
           cout<<" ";
        }
        cout<<w.first<<"/"<<w.second;
    }
    return 0;
}