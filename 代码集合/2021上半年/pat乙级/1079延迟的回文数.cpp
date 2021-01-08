#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool judge(int x)
{
    string sw = to_string(x);
    int i = 0, j = sw.size() -1;
    while(i < j)
    {
        if(sw[i] != sw[j])
        {
            return false;
        }
        ++i;
        --j;
    }
    return true;
}
int main()
{
    string str;
    getline(cin,str);
    string str1 = str;
    string str2 = str1;
    reverse(str2.begin(),str2.end());
    int i;
    bool flag = false;
    for(i = 0;i < 10;++i)
    {
        int sum = stoi(str1) + stoi(str2);
        cout<<str1<<" + "<<str2<<" = "<<sum<<endl;
        if(judge(sum))
        {
            cout<<sum<<" is a palindromic number."<<endl;
            flag = true;
            break;
        }
        str1 = to_string(sum);
        str2 = str1;
        reverse(str2.begin(),str2.end());

    }
    if(!flag)
    {
        cout<<"Not found in 10 iterations."<<endl;
    }
    return 0;
}