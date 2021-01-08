#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    int hh = stoi(str.substr(0,2));
    int mm = stoi(str.substr(3,2));
    if(hh < 12 || (hh == 12 && mm == 0))
    {
        cout<<"Only "<<str<<".  Too early to Dang."<<endl;
    }
    else 
    {
        int cnt = 0;
        cnt = hh - 12;
        if(mm != 0)
            cnt++;
        for(int i = 0;i < cnt;++i)
            cout<<"Dang";
    }
    return 0;
}