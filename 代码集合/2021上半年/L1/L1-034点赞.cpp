#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
using pii = pair<int,int>;
int main()
{
    map<int,int> ms;
    set<int> st;
    int N;
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        int K;
        cin>>K;
        while (K--)
        {
            int id;
            cin>>id;
            st.insert(id);
            ++ms[id];
        }
        
    }
    vector<pii> res;
    for(auto &w : st)
    {
        res.push_back({ms[w],w});
    }
    sort(res.begin(),res.end(),[](auto &e1 ,auto &e2){ if(e1.first != e2.first)return e1.first > e2.first;return e1.second > e2.second;});
    cout<<res[0].second<<" "<<res[0].first<<endl;
    return 0;
}