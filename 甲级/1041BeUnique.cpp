#include<iostream>
#include<vector>
using namespace std;
int flag[100005];
int main()
{
    int n;
    cin>>n;
    vector<int> st;
    for(int i = 0;i < n;++i)
    {
        int x;
        cin>>x;
        flag[x]++;
        st.push_back(x);
    }
    bool winer = false;
    for(auto &e : st)
    {
        if(flag[e] == 1)
        {
            winer = true;
            cout<<e<<endl;
            break;
        }
    }
    cout<<(!winer ? "None\n" : "");
    return 0;
}