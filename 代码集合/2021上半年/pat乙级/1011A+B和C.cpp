#include<iostream>
#include<algorithm>
using namespace std;
typedef long long pi;
int main()
{
    int T;
    cin>>T;
    for(int i = 1;i <= T;++i)
    {
        pi A,B,C;
        cin>>A>>B>>C;
        cout<<"Case #"<<i<<":";
        if(A + B > C)
            cout<<" true";
        else 
            cout<<" false";
        cout<<endl;
    }
    return 0;
}