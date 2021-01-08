#include<iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    char c;
    cin>>c;
    int l = ((N*0.5) + 0.5);
    for(int i = 0;i < l;++i)
    {
        for(int j = 0;j < N;++j)
        {
            cout<<c;
        }
        cout<<endl;
    }
    return 0;
}