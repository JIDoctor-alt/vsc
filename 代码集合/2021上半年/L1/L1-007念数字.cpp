#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str[11] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu","fu"};
    string ct;
    getline(cin,ct);
    for(int i = 0;i < ct.length();++i)
    {
        if(i == 0)
            cout<<(ct[i] == '-' ? str[10] : str[ct[i] - '0']);
        else 
            cout<<" "<<str[ct[i] - '0'];
    }
    return 0;
}