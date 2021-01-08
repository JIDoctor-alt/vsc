#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;
map<char,bool> m;
set<char> st;
map<char,bool> iskey;
int main()
{
    int k;
    cin>>k;
    string str;
    cin>>str;
    char c = '#';
    str += c;
    int cnt = 1;
    for(int i = 0;i < str.size();++i)
    {
        if(c == str[i])
        {
            ++cnt;
        }
        else 
        {
            if(cnt % k != 0)
                iskey[c] = true;//一定是好键盘
            cnt = 1;
        }
        //难点
        if(i != str.size() - 1)  
            m[str[i]]  = (cnt % k == 0);//可能坏
        c = str[i];
    }
    for(int i = 0;i < str.size() - 1;++i)
    {
        if(iskey[str[i]] == true)//确定坏键盘
        {
            m[str[i]] = false;//之前好的一定不坏
        }
    }
    for(int i = 0;i < str.size() - 1;++i)
    {
        if(m[str[i]]&&!st.count(str[i]))
        {
            cout<<str[i];
            st.insert(str[i]);
        }
    }
    cout<<endl;
    for(int i = 0;i < str.size() - 1;++i)
    {
        cout<<str[i];
        if(m[str[i]])
            i += k - 1;
    }
    return 0;
}