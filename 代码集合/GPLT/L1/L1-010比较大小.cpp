#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> ans;
    for(int i = 0;i < 3;++i)
    {
        int id;
        cin>>id;
        ans.push_back(id);
    }
    sort(ans.begin(),ans.end());
    for(int i = 0;i < 3;++i)
    {
        cout<<ans[i];
        if(i != 2)
            cout<<"->";
    }
}