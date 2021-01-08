#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> ves;
    for(int i = 0;i < 3;++i)
    {
        int x;
        cin>>x;
        ves.push_back(x);
    }
    sort(ves.begin(),ves.end());
    cout<<ves[0];
    for(int i = 1;i < 3;++i)
        cout<<"->"<<ves[i];
    return 0;
}