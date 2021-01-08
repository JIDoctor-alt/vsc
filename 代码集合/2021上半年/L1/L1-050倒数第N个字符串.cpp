#include<iostream>
#include<string>
using namespace std;
int main()
{
    int L,N;
    cin>>L>>N;
    string str = "";
    int fl = 1;
    for(int i = 1;i <= L;++i)
        fl *= 26;
    fl -= N;
    for(int i = 0;i < L;++i)
    {
        char c = 'a';
        str =  (char)(c + (fl%26)) + str;
        fl /= 26;
    }

    cout<<str<<endl;
    
    return 0;
}