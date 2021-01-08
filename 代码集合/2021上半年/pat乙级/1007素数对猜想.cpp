#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
bool Valid(int x)
{
    if(x == 1)
        return false;
    for(int i = 2;i <= sqrt(x);++i)
    {
        if(x % i == 0)
            return false;
    }
    return true;
}
using namespace std;
int main()
{
    int N;
    cin>>N;
    vector<int> res;
    for(int i = 1;i <= N;++i)
    {
        if(Valid(i))
        {
            res.push_back(i);
        }
    }
    int ans  = 0;
    for(int i = 0;i < res.size() - 1; ++i)
    {
        if(res[i+1] - res[i] == 2)
        {
            ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}