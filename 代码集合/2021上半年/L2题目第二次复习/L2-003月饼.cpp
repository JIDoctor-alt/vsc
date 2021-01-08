#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
using pii = pair<double,double>;
int N,D;
bool cmp(pii &e1,pii &e2)
{
    return e1.second/e1.first > e2.second/e2.first;
}
int main()
{
    cin>>N>>D;
    vector<pii> res;
    res.resize(N);
    for(int i = 0; i < N;++i)
    {
        cin>>res[i].first;
    }
    for(int i = 0;i < N;++i)
    {
        cin>>res[i].second;
    }
    sort(res.begin(),res.end(),cmp);
    double sum = 0;
    for(int i = 0;i < N;++i)
    {
        double price = res[i].second , weight = res[i].first;
        if(D - weight >= 0)
        {
            sum += price;
            D -= weight;
        }
        else 
        {
            sum = sum + (price/weight)*D;
            break;
        }
    }
    cout<<fixed<<setprecision(2)<<sum<<endl;
    return 0;
}