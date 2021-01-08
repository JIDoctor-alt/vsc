#include<iostream>
#include<string>
using namespace std;
int main()
{
    string ans[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    string str;
    getline(cin,str);
    int sum = 0;
    for(int i = 0;i < str.size();++i)
    {
        sum += (str[i] - '0');
    }
    string res = to_string(sum);
    for(int i = 0;i < res.size();++i)
    {
        if(i != 0)
            cout<<" ";
        cout<<ans[(res[i] - '0')];
    }
    return 0;
}