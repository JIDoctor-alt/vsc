#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a,b;
    string sum;
    cin>>a>>b;
    a += b;
    if(a < 0)
    {
        cout<<"-";
        a = 0 - a;
    }
    sum = to_string(a);
    int len = int(sum.size());
    cout<<sum[0];
    for(int i = 1;i < len;++i)
    {
        if((len - i)% 3 ==0)
            cout<<",";
        cout<<sum[i];
    }
    cout<<"\n";
    return 0;
}