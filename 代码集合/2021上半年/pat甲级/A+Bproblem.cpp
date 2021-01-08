#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int ws = a + b;
    int sum = ws;
    if(sum < 0)
        sum = 0 - sum;
    string str = to_string(sum);
    string res  =  "";
    int ans = 0;
    for(int i = str.size()-1; i >= 0;--i)
    {
        ++ans;
        res = str[i] + res;
        if(i != 0 && ans % 3 == 0)
            res = "," + res;
    }
    if(ws < 0)
    cout<<"-";
    cout<<res<<endl;
    return 0;
}