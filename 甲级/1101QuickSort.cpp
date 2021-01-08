#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<int> a,b;
set<int> st;
int N;
int main()
{
    int max_left = 0;
    cin>>N;
    a.resize(N);
    b.resize(N);
    for(int i = 0;i < N;++i)
    {
        cin>>a[i];
        b[i] = a[i];
    }
    sort(a.begin(),a.end());
    for(int i = 0;i < N;++i)
    {
        if(a[i] == b[i] && max_left < b[i])
            st.insert(b[i]);
        max_left = max(max_left,b[i]);
    }
    int cnt = int(st.size());
    cout<<cnt<<endl;
    int i = 0;
    for(auto &w : st)
    {
        cout<<((i++)!= 0 ? " " : "")<<w;
    }
    cout<<endl;
    return 0;
}