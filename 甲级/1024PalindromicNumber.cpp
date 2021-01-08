#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string additionLargeNum(string str1,string str2)
{
    int l = int(str1.size());
    int digit = 0;
    for(int i = l - 1;i >= 0;--i)
    {
        int temp = (str1[i] - '0')+ (str2[i] - '0') + digit;
        digit = temp/10;
        str1[i] = (temp%10) + '0';
    }

    if(digit)
        str1 = to_string(digit) + str1;
    return str1;
}
int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;
    
    int i = 1;
    for(;i <= k;++i)
    {
        string ctr = str;
        reverse(ctr.begin(),ctr.end());
        if(ctr == str)
            break;
        str = additionLargeNum(str,ctr);
    }
    cout<<str<<endl;
    cout<<i-1<<endl;
    return 0;
}