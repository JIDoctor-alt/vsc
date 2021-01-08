#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main()
{
   int x;
   cin>>x;
   if((x + 2) % 7 == 0)
        cout<<7;
    else 
        cout<<((x + 2 ) % 7)<<endl;
    return 0;
}