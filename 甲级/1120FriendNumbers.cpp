#include<iostream>
#include<set>
#include<string>
using namespace std;
int N,cnt;
set<int> st;
int getFriedId(string str)
{
    int sum = 0;
    for(auto &c : str)
    {
        sum += (c - '0');
    }
    return sum;
}
int main()
{
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        string str;
        cin>>str;
        st.insert(getFriedId(str));
    }
    cnt = st.size();
    cout<<cnt<<endl;
    cnt = 0;
    for(auto &i : st)
    {
        cout<<(cnt++ != 0 ? " " : "")<<i;
    }
    return 0;
}