#include<iostream>
#include<vector>
#include<functional>
#include<utility>
#include<algorithm>
#include<iomanip>

#define EPS 1e-6

using namespace std;

using pii = pair<double,double>;
int N,W;
vector<pii> stu;
bool cmp(pii & a, pii & b)
{
    return a.first/a.second - b.first/b.second > EPS;
}
int main()
{
    cin>>N>>W;
    for(int i = 0;i < N;++i)
    {
        double v,h;
        cin>>v>>h;
        stu.push_back({v,h});
    }
    sort(stu.begin(),stu.end(),cmp);
    double total = 0,countW = 0;
    for(int i = 0;i < N;++i)
    {
        if(countW + stu[i].second <= W)
        {
            total += stu[i].first;
            countW += stu[i].second;
        }
        else 
        {
            total += (stu[i].first/stu[i].second)*(W - countW);
            break;
        }
    }
    cout<<fixed<<setprecision(1)<<total<<endl;
    return 0;
}