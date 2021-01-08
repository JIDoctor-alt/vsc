#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    string str;
    getline(cin,str);
    while(str != "6174")
    {
    sort(str.begin(),str.end());
    string str1,str2;
    str1 = str;
    reverse(str.begin(),str.end());
    str2 = str;
    int a = stoi(str2);
    int b = stoi(str1);
    printf("%04d - %04d = %04d\n",a,b,(a-b));
    str = to_string((a-b));
    if(str1 == str2)
        break;
    }
   
    return 0;
}