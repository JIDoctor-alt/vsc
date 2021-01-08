#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    int ans = 0;
    for(int i = 0;i < str.size();++i)
    {
        int len = 1;
        //奇数
        int j = 1;
        while(i - j >= 0 && i + j < str.size()&& str[i + j] == str[i - j])
        {
            len += 2;
            ++j;
        }
        ans = max(ans,len);

        len = 0;
        j = 0;
        while(i - j >= -1 && i + j < str.size() && str[i + j] == str[i - (j + 1)])
        {
            len += 2;
            ++j;
        }
        ans = max(ans,len);
    }
    cout<<ans<<endl;
    return 0;
}