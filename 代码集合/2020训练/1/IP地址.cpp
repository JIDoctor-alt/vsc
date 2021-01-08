#include<iostream>
#include<string>
#include<vector>
using namespace std;
int quan[8] = {1,2,4,8,16,32,64,128};
int main()
{
    string str;
    getline(cin,str);
    int sum = 0;
    int cnt = 7;
    vector<int> st;
    for(int i = 0;i < str.size();++i)
    {

        sum += (str[i] == '1' ? quan[cnt] :0);
        --cnt;
        if((i + 1) % 8 == 0)
        {
            st.push_back(sum);
            sum = 0;
            cnt = 7;
        }

    }
    cout<<st[0];
    for(int i = 1;i < st.size();++i)
        cout<<"."<<st[i];
    return 0;
}