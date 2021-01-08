#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    int ans = 0;
    double sum = 0;
    int le = str.length();
    for(int i = 0;i < str.length(); ++i)
    {
        if(str[i] == '2')
            ans++;
    }
    if(str[0] == '-')
        --le;
    sum = ans/(le * 1.0);
    if(str[0] == '-')
        sum *= 1.5;
    if(!((str[str.length() -1] - '0')%2))
        sum *= 2;
    cout<<fixed<<setprecision(2)<<sum*100<<"%"<<endl;
    return 0;
}