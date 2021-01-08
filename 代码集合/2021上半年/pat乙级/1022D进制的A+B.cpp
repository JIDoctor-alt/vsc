#include<iostream>
#include<vector>
using namespace std;
int main()
{
    long long A,B,SUM;
    int D;
    cin>>A>>B>>D;
    SUM = A + B;
    vector<int> res;
    while (SUM)
    {
       res.push_back(SUM%D);
       SUM /= D;
    }
    for(int i = res.size() - 1;i >= 0;--i)
    {
        cout<<res[i];
    }
    return 0;
}