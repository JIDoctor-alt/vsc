#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int f(string &str){
    int sum = 0;
    for(int i = 0;i < str.size();++i){
        if(isdigit(str[i])){
            sum = sum * 10 + (str[i] - '0');
        }else{
            return -1;
        }
    }
    if(sum <= 0 || sum > 1000)
        return -1;
    return sum;
}
int main()
{
    string str;
    getline(cin,str);
        int x = str.find(' ');
    string a = str.substr(0,x);

    string b = str.substr(x+1, str.size() - x-1);
    int s1 = f(a), s2 = f(b);
    if(s1 == -1)
    {
        cout<<"?";
    }
    else 
    {
        cout<<s1;
    }
    cout<<" + ";
    if(s2 == -1)
    {
        cout<<"?";
    }
    else
    {
        cout<<s2;
    }
    cout<<" = ";
    if(s1 != -1 && s2 != -1)
    {
        cout<<(s1 + s2);
    }
    else
    {
        cout<<"?";
    }
    
    
    return 0;
}