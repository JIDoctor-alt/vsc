#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int a[100005];
int main()
{
    int N;
    cin>>N;
    set<int> st;
    for(int i = 0;i < N;++i)
    {
        int num;
        cin>>num;
        auto x = st.upper_bound(num);
        if(x != st.end())
        {
            st.erase(x);
        }
        st.insert(num);
    }
    cout<<st.size()<<endl;
    return 0;
}