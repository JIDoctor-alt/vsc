#include<iostream>
using namespace std;
int main()
{
    int k;
    cin>>k;
    string str;
    int ans = 0;
    while(cin>>str && str != "End")
    {
        if(ans == k)
        {
            cout<<str<<endl;
        }
    }
    return 0;
}