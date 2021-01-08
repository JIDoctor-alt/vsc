#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    string str;
    map<char,int> ms;
    getline(cin,str);
    for(int i = 0;i < str.size();++i){
        char c = toupper(str[i]);
        ms[c]++;
    }
    while(true){
        if(ms['G']){
            cout<<'G';
            ms['G']--;
        }
        if(ms['P']){
            cout<<'P';
            ms['P']--;
        }
        if(ms['L']){
            cout<<'L';
            ms['L']--;
        }
        if(ms['T']){
            cout<<'T';
            ms['T']--;
        }
        if(ms['G'] == 0 && ms['P'] == 0 && ms['L'] == 0 && ms['T'] == 0)
            break;
    }
    return 0;
}