#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
using pii = pair<int,char>;
int main()
{
    string str;
    map<char,int> ms;
    getline(cin,str);
    char c;
    for(int i = 0;i < str.size();++i)
    {
        c = str[i];
        if(!islower(c))
        {
            c = tolower(c);
        }
        ++ms[c];
    }
    map<char,int>::iterator i;
    vector<pii> ves;
    for(i = ms.begin();i != ms.end();++i)
    {
        char  c = i->first;
        int num = i->second;
        ves.push_back({num,c});
    }
    sort(ves.begin(),ves.end(),[](auto &e1,auto &e2){if(e1.first != e2.first){return e1.first > e2.first;}else {return e1.second < e2.second;}});
    for(auto w : ves)
    {
        char c = w.second;
        if(isalpha(c))
        {
            cout<<c<<" "<<w.first<<endl;
            break;
        }
    }
    return 0;
}