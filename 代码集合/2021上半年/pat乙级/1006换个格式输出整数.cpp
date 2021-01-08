#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[3];
    for(int i = 2;i >= 0;--i)
    {
        a[i] = n%10;
        n /= 10;
    }
    for(int i = 0;i < 3;++i)
    {
        for(int j = 1;j <= a[i];++j)
        {
            if(i == 0)
                cout<<"B";
            if(i == 1)
                cout<<"S";
            if(i == 2)
                cout<<j;
        }
    }
    return 0;
}