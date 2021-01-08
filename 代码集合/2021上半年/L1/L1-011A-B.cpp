#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
    string A;
    string B;
    getline(cin,A);
    getline(cin,B);
    set<char> st;
    for(int i = 0;i < B.length();++i)
        st.insert(B[i]);
    for(auto i : A)
    {
        if(st.count(i) == 0)
            cout<<i;
    }
    cout<<endl;
    return 0;
}