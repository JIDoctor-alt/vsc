#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string str;
    int ans = 0;
    string flagA = " " , flagB = " ";
    while(cin>>str&& str != ".")
    {
        ++ans;
        if(ans == 2)
            flagA = str;
        if(ans == 14)
            flagB = str;
    }
    if(flagA != " "&& flagB != " ")
    {
        cout<<flagA<<" and "<<flagB<<" are inviting you to dinner..."<<endl;
    }
    else if(flagA != " "&&flagB == " ")
    {
        cout<<flagA<<" is the only one for you..."<<endl;
    }
    else if(flagA == " "&& flagB == " ")
    {
        cout<<"Momo... No one is for you ..."<<endl;
    }
    return 0;
}