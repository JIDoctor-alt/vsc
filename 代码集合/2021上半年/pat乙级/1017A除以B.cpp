#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    string res  = "";
    int B;
    cin>>str>>B;
    int x = str[0] - '0' , R;
    int i = 0;
    while(true)
    {
        //res = res*10 + x/B;
        res = res + to_string(x/B);
        R = x % B;
        if (i == str.size()- 1)
        {
            break;
        }
        
        x = (x % B)*10 + (str[i+1] - '0');
        ++i;
    }
    for(int i = 0;i < res.size();++i)
    {
        if(i == 0 && res[i] == '0')
        {
            res.erase(0,1);
        }
    }
    cout<<res<<" "<<R;
    return 0;
}