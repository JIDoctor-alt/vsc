#include<iostream>
#include<string>
using namespace std;
string Valid(string &x)
{
    string str = x;
    while(str[0] == '0')
    {
        str = str.substr(1);
    }
    return str;
}
int main()
{
    int x;
    cin>>x;
    int num = 1,ans = 0;
    string str = "";
    while(num)
    {
        ++ans;
        if(num/x)
        {
            str += to_string(num/x);
            num %= x;
            if(num == 0)
                break;
        }
        else 
        {
            str += "0";
        }
        num = num * 10 + 1;
    }
    cout<<Valid(str)<<" "<<ans<<endl;
    return 0;
}