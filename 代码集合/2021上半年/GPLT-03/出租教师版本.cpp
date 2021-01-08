#include<iostream>
#include<set>
#include<string>
#include<functional>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int a[15];
    set<int,greater<int>> st;
    for(auto x : s)
    {
        st.insert(x - '0');
    }
    int i = 0;
    for(auto x : st)
    {
        a[x] = i++;
    }
    cout<<"int[] arr = new int[]{";
    int t = 0;
    for(auto x : st)
    {
        cout<<x<<(t++ != i - 1 ? "," : "};\n");
    }
    t = 0;
    cout<<"int[] index = new int[]{";
    for(auto x : s)
    {
        cout<<a[x - '0']<<(t++ != s.length()-1 ? "," : "};\n");
    }
    return 0;
}