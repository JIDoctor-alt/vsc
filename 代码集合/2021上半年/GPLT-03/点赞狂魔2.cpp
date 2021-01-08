#include<iostream>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
struct info
{
    string id;
    int cnt;
    double avg;
};
int main()
{
    int N;
    cin>>N;
    vector<info> v;
    while (N--)
    {
        string id;
        cin>>id;
        int  K;
        cin>>K;
        //存储有多少标签
        set<int> st;
        for(int i = 0;i < K;i++)
        {
            int x;
            cin>>x;
            st.insert(x);
        }
        v.push_back({id,st.size(),K*1.0/st.size()});
    }
    sort(v.begin(),v.end(),[](auto & x,auto & y){return x.cnt == y.cnt ? x.avg < y.avg : x.cnt > y.cnt;});
    v.push_back({"-",0,0});
    v.push_back({"-",0,0});
    cout<<v[0].id<<" "<<v[1].id<<" "<<v[2].id<<endl;
    return 0;
}