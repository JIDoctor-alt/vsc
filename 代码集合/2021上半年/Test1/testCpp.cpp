#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    string str1;
    cin >> str1;
    set<string> st;
    st.insert("he");
    map<string, int> mp;
    for (auto i : v)
        cout << i << endl;
    cout << "hello, world!\n";
    cout << *max_element(v.begin(), v.end()) << endl;
    return 0;
}