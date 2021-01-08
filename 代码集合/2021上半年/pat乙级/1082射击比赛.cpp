#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include<numeric>
using namespace std;
int main()
{
    int id;
    int x,y;
    int N,dis;
    cin>>N;
    int max_id ,min_id,max_dis = -1,min_dis = 1<<30;
    while(N--)
    {
        cin>>id>>x>>y;
        dis = x * x + y * y;
        if(min_dis > dis)
        {
            min_id = id;
            min_dis = dis;
        }
        if(max_dis < dis)
        {
            max_id = id;
            max_dis = dis;
        }
    }
    cout<<fixed<<setw(4)<<setfill('0')<<min_id<<" ";
    cout<<fixed<<setw(4)<<setfill('0')<<max_id<<endl;
    return 0;
}