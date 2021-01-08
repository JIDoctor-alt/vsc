#include<iostream>
#include<string>
using namespace std;
int main()
{
    char d;
    int N;
    cin>>d>>N;
    string str = "";
    int i = 1;
    while(true)
    {
        ++i;
        str = str + (d - '0') + "1";
        
    }
    return 0;
}