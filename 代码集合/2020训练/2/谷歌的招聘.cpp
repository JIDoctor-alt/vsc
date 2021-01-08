#include<iostream>
#include<string>
#include<math.h>
#include<iomanip>
#include<algorithm>
//③setw和setfill 被称为输出控制符，使用时需要在程序开头写上#include "iomanip.h"，否则无法使用。
using namespace std;
int l,k;
bool judge(long long x)
{
    if(x == 1)
        return false;

    for(long long i = 2;i <= sqrt(x);++i)
    {
        if(x % i == 0)
            return false;
    }

    return true;
}
int main()
{
    cin>>l>>k;
    getchar();

    string str;
    getline(cin,str);

    bool flag = false;
    if(l )
    for(int i = 0;i <= l - k;++i)
    {
        string cs = str.substr(i,k);
        long long CountNum = stoi(cs);

        if(judge(CountNum))
        {
            flag = true;
            cout<<setfill('0')<<setw(k)<<CountNum<<endl;
            break;
        }
    }
    if(!flag)
        cout<<"404\n";

    return 0;
}