#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    set<int> st;
    for(int i = 0;i < str.size();++i){
        st.insert((str[i] - '0'));
    }
    vector<int> arr(10);
    cout<<"int[] arr = new int[]{";
    set<int>::reverse_iterator i;
    int ans = 0;
    for(i=st.rbegin();i != st.rend();++i){
        int x = *i;
        if(i != st.rbegin())
            cout<<",";
        cout<<x;
        arr[x] = ans++;
    }
    cout<<"};\n";
    cout<<"int[] index = new int[]{";
    for(int i = 0;i < str.size();++i){
        int ix = arr[(str[i] - '0')];
        if(i != 0)
            cout<<",";
        cout<<ix;
    }
    cout<<"};\n";
    return 0;
}