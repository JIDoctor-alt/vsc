#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    int ans = 1;
    for(int i = 0;i < str.size();++i){

        int len = 1;
        int st = i - 1;
        int ed = i + 1;
        while(st >= 0 && ed < str.size() && str[st] == str[ed]){
            len += 2;
            --st;
            ++ed;
        }
        ans = ( ans > len ? ans : len);

         len = 0;
         st = i ;
        ed = i + 1;
        while(st >= 0 && ed < str.size() && str[st] == str[ed]){
            --st;
            ++ed;
            len += 2;
        }

        ans = (ans > len ? ans : len);
    }
    cout<<ans<<endl;
    return 0;
}