#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
    set<int> s;
    int N;
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        int num;
        cin>>num;
        if(s.upper_bound(num) != s.end())
        {
           int t = *s.upper_bound(num);
           s.erase(t);
        }
        s.insert(num);
    }
    cout<<s.size()<<endl;
    return 0;
}