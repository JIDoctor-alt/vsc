#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int N;
    cin>>N;
    map<char,char> ms;
    ms['A'] = '1';
    ms['B'] = '2';
    ms['C'] = '3';
    ms['D'] = '4';
    getchar();
    string str;
    vector<char> res;
    for(int i = 0;i < N;++i)
    {
        getline(cin,str);
        int index = str.find('T');
        char c = ms[str[index - 2]];
        res.push_back(c);
    }
    for(auto i : res)
    {
        cout<<i;
    }
    return 0;
}