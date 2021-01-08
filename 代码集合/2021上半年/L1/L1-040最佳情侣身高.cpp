#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        double re;
        char sex;
        cin>>sex>>re;
        if(sex == 'M')
        {
            cout<<fixed<<setprecision(2)<<(re/1.09)<<endl;
        }
        else if(sex == 'F')
        {
            cout<<fixed<<setprecision(2)<<(re*1.09)<<endl;
        }
    }
    return 0;
}