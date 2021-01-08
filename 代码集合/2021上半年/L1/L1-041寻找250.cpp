#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> ans;
    int num;
    int  flag = 0;
    while(cin>>num)
    {
        ans.push_back(num);
        if(num == 250 && !flag)
        {
            flag  = ans.size();
        }
    }
    cout<<flag<<endl;
    return 0;
}