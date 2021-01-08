#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    int x = stoi(str.substr(0,2));
    int y = stoi(str.substr(3,2));
    if( x < 12 || (x == 12 && y == 0))
        cout<<"Only "<<str<<".  Too early to Dang."<<endl;
    else 
    {
        int ans = x - 12;
        if(y > 0)
            ans++;
        while (ans--)
        {
            cout<<"Dang";
        }
        
    }
    return 0;
}