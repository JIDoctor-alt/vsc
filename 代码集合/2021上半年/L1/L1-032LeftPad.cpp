#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    char c;
    int n;
    string str;
    cin>>n>>c;
    getchar();
    getline(cin,str);
    int len = str.length();
    if(n <= len)
    {
        for(int i = len - n; i < len;++i)
           cout<<str[i];
        cout<<endl;
    }
    else 
    {
        for(int i = 0;i < n - len;++i)
            cout<<c;
        cout<<str<<endl;
    }
    return 0;
}