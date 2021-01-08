#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    int offset;
    cin>>offset;
    if(offset < 0)
        offset = (offset % 26) + 26;
    else 
        offset = offset % 26;
    for(auto &e : str)
    {
        if(!isalpha(e))//判断是英文字母
        {
            cout<<e;
            continue;
        }
        char c = (islower(e) ? 'a' : 'A');
        e = c + (e - c + offset)%26;
        cout<<e;
    }
    return 0;
}