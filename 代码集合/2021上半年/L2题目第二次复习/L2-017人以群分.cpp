#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> st;
int main()
{
    cin>>N;
    int s = 0;
    for(int i = 0;i < N;++i)
    {
        int num;
        cin>>num;
        s += num;
        st.push_back(num);
    }
    sort(st.begin(),st.end());
    int sum = 0;
    for(int i = 0;i < N/2;++i)
    {
        sum += st[i];
    }
    cout<<"Outgoing #: "<<(N+1)/2<<endl;
    cout<<"Introverted #: "<<N/2<<endl;
    cout<<"Diff = "<<(s - sum - sum)<<endl;
    return 0;
}