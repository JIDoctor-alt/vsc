#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    double sum = 1,ans;
    ans = str.size();
    if(str[0] == '-')
    {
        sum *= 1.5;
        --ans;
    }
    if((str[str.size() - 1] - '0') % 2 == 0)
        sum *= 2;
    int cnt = 0;
    for(int i = 0;i < str.size();++i)
    {
        if(str[i] == '2')
            ++cnt;
    }
    cout<<fixed<<setprecision(2)<<((cnt/ans)*sum * 100)<<"%"<<endl;
    return 0;
}