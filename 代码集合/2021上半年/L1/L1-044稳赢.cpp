#include<iostream>
#include<string>
using namespace std;
int main()
{
    int K;
    cin>>K;
    string str;
    int ans = 0;
    while (cin>>str && str != "End")
    {
        
        if(ans == K)
        {
            cout<<str<<endl;
            ans = 0;
        }
        else 
        {
            if(str == "ChuiZi")
            {
                cout<<"Bu"<<endl;
            }
            else if(str == "JianDao")
            {
                cout<<"ChuiZi"<<endl;
            }
            else if(str == "Bu")
            {
                cout<<"JianDao"<<endl;
            }
            ++ans;
        }
        
    }
    
    return 0;
}