#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    set<char> st;
    for(int i = 0;i < str2.size();++i)
        st.insert(str2[i]);
    for(int i = 0;i < str1.size();++i){
        if(!st.count(str1[i])){
            cout<<str1[i];
        }
    }
    return 0;
}