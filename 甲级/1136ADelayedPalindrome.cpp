#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string getCount(string str)
{
    string sum = str;
    int len = int(str.size());
    int digit = 0;
    int j = len - 1,i = 0;
    for(;i < len && j >= 0;++i,--j)
    {
        int x = (sum[j] - '0') + (str[i] - '0') + digit;
        sum[j] = (x%10 + '0');
        digit = x/10;
    }
    if(digit)
        sum = to_string(digit) + sum;
    return sum;
}
bool Ispalindromic(string str)
{
    int len = int(str.size());
    for(int i = 0;i < len/2;++i)
    {
        if(str[i] != str[len - 1 - i])
            return false;
    }
    return true;
}
int main()
{
    string str;
    getline(cin,str);
    int i;
    for(i = 0;i < 10;++i)
    {
        string ctr = str;
        reverse(ctr.begin(),ctr.end());
        if(Ispalindromic(str))
        {
            cout<<str<<" is a palindromic number.\n";
            break;
        }
        string x = getCount(str);
        cout<<str<<" + "<<ctr<<" = "<<x<<endl;
        str = x;
    }
    if(i == 10)
        cout<<"Not found in 10 iterations.\n";
    return 0;
}