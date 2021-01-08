#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int N,M;
bool Valid(int x)
{
    if(x == 1)
        return false;
    for(int i = 2;i <= sqrt(x);++i)
    {
        if(x % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    vector<int> stu;
    cin>>M>>N;
    int ans = 0,i = 0;
    while(ans < N)
    {
        ++i;
        if(Valid(i))
        {
            ++ans;
            if(ans >= M)
            {
                    stu.push_back(i);
            }
        }
    }

    int x = 1;
    for(int i = 0;i < stu.size();++i)
    {
        cout<<stu[i];
        if(x % 10 == 0)
        {
            cout<<"\n";
        }
        else 
        {
            if(x != stu.size())
            {
                 cout<<" ";
            }
        }
        ++x;   
    }
    return 0;
}