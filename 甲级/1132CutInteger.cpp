#include<iostream>
#include<string>
using namespace std;
int N;
string str;
int main()
{
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        int c;
        cin>>c;
        string str = to_string(c);
        int  k = str.size() / 2;
        int a = stoi(str.substr(0,k));
        int b = stoi(str.substr(k));
        if(a*b == 0)
        {
            cout<<"No\n";
        }
        else 
        {
            cout<<(c % (a*b) == 0 ? "Yes\n" : "No\n");
        }    
    }
    return 0;
}