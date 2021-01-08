#include<iostream>
#include<set>
#include<string>

using namespace std;
int n;
bool judge(int x)
{
    string str = to_string(x);
    set<int> st;
    for(int i = 0;i < str.length();++i)
        st.insert((str[i] - '0'));
    if(str.size() != 4)
        st.insert(0);
    return st.size() == n;
}
int main()
{
    int y,ans = 0;
    cin>>y>>n;

    while(true)
    {
        if(judge(y))
        {
            printf("%d %04d",ans,y);
            break;
        }
        ++ans;
        ++y;
    }
    return 0;
}