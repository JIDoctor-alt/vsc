#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    string str;
    cin>>n;
    while(cin>>str)
    {
        int x = (str[0] - '0') + (str[1] - '0')+ (str[2] - '0');
        int y = (str[3] - '0') + (str[4] - '0')+ (str[5] - '0');
        cout<<(x == y ? "You are lucky!\n" : "Wish you good luck.\n");
    }
    return 0;
}