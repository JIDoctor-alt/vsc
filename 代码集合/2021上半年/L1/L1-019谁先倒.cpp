#include<iostream>
#include<vector>
using namespace std;
struct  Edge
{
    int x,y,a,b;
};

int main()
{
    int f1, f2 ,ans1 = 0 , ans2 = 0;
    cin>>f1>>f2;
    int N;
    cin>>N;
  
    for(int i = 0;i < N;++i)
    {
        int x,y, a , b;
       // x = i.x, y = i.y ,a = i.a , b = i.b;
       cin>>x>>y>>a>>b;
        int w = x + a;
        if((b == w && y == w)||(b != w && y != w))
            continue;
        if(y == w)
            ++ans1;
        if(b == w)
            ++ans2;
        if(f1 - ans1 < 0)
        {
            cout<<"A"<<endl;
            cout<<ans2<<endl;
            break;
        }
        if(f2 - ans2 < 0)
        {
            cout<<"B"<<endl;
            cout<<ans1<<endl;
            break;
        }
    }
    return 0;
}