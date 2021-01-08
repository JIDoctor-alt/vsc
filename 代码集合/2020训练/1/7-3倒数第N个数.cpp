#include<iostream>
#include<string>
using namespace std;
int main()
{
    int l,n;
    cin>>l>>n;
    string ct ;
    int x;
    for(int i = 0;i < l - 1;++i)
    {
         x = n % 26;
        ct += ('z' - x );
        n/= 26;
    }
    x = n % 26;
    ct += ('z' - x );
    cout<<ct<<endl;
    return 0;
}