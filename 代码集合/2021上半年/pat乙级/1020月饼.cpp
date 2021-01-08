#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#define EPS 1e-3
using namespace std;
using pii = pair<double,double>;
bool cmp(pii &e1,pii &e2)
{
    double w1 = e1.first /e1.second;
    double w2 = e2.first/e2.second;
    return w1 - w2  > EPS; 
}
int main()
{
    vector<pii> stu;
    int N,D;
    cin>>N>>D;
    stu.resize(N);
    for(int i = 0;i < N;++i)
    {
        double price;
        cin>>price;
        stu[i].second = price;
    }
    for(int i = 0;i < N;++i)
    {
        double weight;
        cin>>weight;
        stu[i].first = weight;
    }
    sort(stu.begin(),stu.end(),cmp);
    double sum = 0;
    for(int i = 0;i < N;++i)
    {
        if(D >= stu[i].second)
        {
            sum += stu[i].first;
            D -= stu[i].second;
        }
        else 
        {
            sum += (stu[i].first/stu[i].second)*D;
            break;
        }
    }
    cout<<fixed<<setprecision(2)<<sum<<endl;
    return 0;
}