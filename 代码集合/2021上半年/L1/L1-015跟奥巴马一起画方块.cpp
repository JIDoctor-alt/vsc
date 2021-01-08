#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int N;
    char c;
    cin>>N>>c;
    int M;
    M = ((N*1.0)/2)+0.5;
    for(int i = 0;i < M;++i)
    {
        for(int j = 0;j < N;++j)
            cout<<c;
        cout<<endl;
    }
    return 0;
}